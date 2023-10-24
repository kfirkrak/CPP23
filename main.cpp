#include <iostream>
#include <vector>

class HalfSpace {
private:
    class Vector {
        std::vector<double> vec;
    public:
        Vector(const double *other, int len) {
            for (int i = 0; i < len; i++) {
                this->vec.push_back(other[i]);
            }
        }

        void print() {
            for (auto num: vec) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }

        double innerProduct(const double *other, int len) {
            double sum = 0;
            for (int i = 0; i < len; i++) {
                sum += other[i] * this->vec[i];
            }
            return sum;
        }
    };

public:
    Vector vec;
    double b;

    HalfSpace(const double *other, int len, double b) : vec(other, len),
                                                        b(b) {};

    int checkOrientation(const double *other, int len) {
        double innerProd = this->vec.innerProduct(other, len);
        if (innerProd < this->b) {
            return -1;
        }
        if (innerProd > this->b) {
            return 1;
        }
        return 0;
    }

    void print_vec() {
        std::cout << "The base vector is: ";
        this->vec.print();
        std::cout << "The translation is: " << this->b << std::endl;
    }
};

void testHalfSpace() {
    double hsVec[2] = {1, 1};
    double b = 0;
    double vec1[2] = {2, 1};
    double vec2[2] = {-1, 1};
    double vec3[2] = {-3, -2.2};

    HalfSpace hs(hsVec, 2, b);
    hs.print_vec();
    std::cout << "Check vector (2,1) " << hs.checkOrientation(vec1, 2)
              << std::endl;
    std::cout << "Check vector (-1,1) " << hs.checkOrientation(vec2, 2)
              << std::endl;
    std::cout << "Check vector (-3,-2.2) " << hs.checkOrientation(vec3, 2)
              << std::endl;
}

int main() {
    testHalfSpace();
    return 0;
}
