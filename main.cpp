#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <limits>
#include <vector>
#include <memory>
#include <random>
#include "color.hpp"
#include "ray.hpp"
#include "vector3.hpp"
#include "hitable.hpp"
#include "sphere.hpp"
#include "hitablelist.hpp"
#include "camera.hpp"
#include "behavioral.hpp"
#include "lambertian.hpp"
#include "metal.hpp"
#include "dielectric.hpp"

using namespace std;

Vector3 color(const Ray &ray, HitableList &world, int depth) {
    HitRecord record;
    if (world.hit(ray, 0.001, std::numeric_limits<float>::max(), record)) {
        Ray scattered;
        Vector3 attenuation(0.0,0.0,0.0);
        if (depth < 50 && record.material != nullptr && record.material->scatter(ray, record, attenuation, scattered)){
            return attenuation * color(scattered, world, depth + 1);
        } else {
            return Vector3(0.0, 0.0, 0.0);
        }
    } else {
        Vector3 udirection = Vector3::makeUnitVector(ray.getDirection());
        float t = 0.5 * (udirection.y() + 1.0);
        return (1.0 -t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1.0);
    }
}

HitableList createRandomScene() {
    random_device rdevice;
    mt19937 mt(rdevice());
    uniform_int_distribution<int> distribuition(-11, 11);

    vector<shared_ptr<Hitable>> buffer;
    buffer.push_back(make_shared<Sphere>(Vector3(0.0f, -1000.0f, 0.0f), 1000, make_shared<Lambertian>(Vector3(0.5f, 0.5f, 0.5f))));
    buffer.push_back(make_shared<Sphere>(Vector3(0.0f, 1.0f, 0.0f), 1.0f, make_shared<Dielectric>(1.3f)));
    buffer.push_back(make_shared<Sphere>(Vector3(-4.0f, 1.0f, 0.0f), 1.0f, make_shared<Lambertian>(Vector3(0.4f, 0.2f, 0.1f))));
    buffer.push_back(make_shared<Sphere>(Vector3(4.0f, 1.0f, 0.0f), 1.0f, make_shared<Metal>(Vector3(0.7f, 0.6f, 0.5f), 0.0)));

    generate_n(back_inserter(buffer), 215, [&distribuition, &mt](){
        float choseMaterial = drand48();

        Vector3 center(distribuition(mt) + 0.9f * drand48(), 0.2f, distribuition(mt) + 0.9f * drand48());
        if ((center - Vector3(4.0f, 0.2f, 0.0f)).length() > 0.9f) {
            if (choseMaterial < 0.7f) {
                return make_shared<Sphere>(center, 0.2f, make_shared<Lambertian>(Vector3(drand48()*drand48(), drand48()*drand48(), drand48()*drand48())));
            } else if (choseMaterial < 0.85) {
                return make_shared<Sphere>(center, 0.2f, make_shared<Metal>(Vector3(float(0.5f*(1 + drand48())), float(0.5f*(1 + drand48())), float(1.0f*drand48())), float(0.5f*drand48())));
            }
        }

        return make_shared<Sphere>(center, 0.2f, make_shared<Dielectric>(1.0f));
    });

    HitableList list(buffer);

    return list;
}

int main(int argc, char *argv[])
{
    int nx = 800;
    int ny = 400;
    int ns = 1;//atoi(argv[1]);

    HitableList world = createRandomScene();

    Vector3 from(13.0f, 2.0f, 3.0f);
    Vector3 to(0.0f, 0.0f, 0.0f);
    float distFocus = 10.0;
    float aperture = 0.1;
    Camera camera(from, to, Vector3(0.0, 1.0, 0.0), 20, float(nx)/float(ny), aperture, distFocus);

    ofstream ostr("sample.ppm", ios::out);
    if (!ostr) {
        cerr << "write file failed" << endl;
        exit(EXIT_FAILURE);
    }

    ostringstream ss;

    ss << "P3\n" << nx << " " << ny << "\n255\n";
    double count = 1;
    for(int j = ny -1; j >= 0; j--) {
        for(int i = 0; i < nx; i++){
            Vector3 col(0.0, 0.0, 0.0);
            for (int s=0; s<ns; s++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                Ray ray = camera.getRay(u, v);
                col = col + color(ray, world, 0);
            }

            col = col / float(ns);
            col = Vector3(sqrt(col.x()), sqrt(col.y()), sqrt(col.z()));
            int ir = int(255.99 * col.x());
            int ig = int(255.99 * col.y());
            int ib = int(255.99 * col.z());

            ss << ir << " " << ig << " " << ib << "\n";
        }

        cout << "Line " << static_cast<int>((count++ / (ny)) * 100) << "% " << " of [" << (ny) << "] finnished" << "\r";
        cout.flush();
    }

    string str = ss.str();
    ostr.write(str.c_str(), str.length());
    ostr.close();

    return 0;
}
