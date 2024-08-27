#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart{
    public:
        FunctionPart(const char& New_Operation, const double& New_Value){
            Operation = New_Operation;
            Value = New_Value;
        }
        double Apply(double Source_value) const{
            if (Operation == '+'){
                return Source_value + Value;
            } else {
                return Source_value - Value;
            }
        }
        void Invert(){
            if (Operation == '+'){
                Operation = '-';
            } else {
                Operation = '+';
            }
        }
    private:
        char Operation;
        double Value;
};

class Function {
    public:
        void AddPart(const char& New_Operation, const double& New_Value){
            parts.push_back({New_Operation, New_Value});
        }
        double Apply(double value) const {
            for (const FunctionPart& part : parts){
                value = part.Apply(value);
            }
            return value;
        }
        void Invert(){
            for (FunctionPart& part : parts){
                part.Invert();
            }
            reverse(begin(parts), end(parts));
        }
    private:
        vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 46) << endl;
    return 0;
}
