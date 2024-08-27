class FunctionPart{
    public:
        FunctionPart(const char& New_Operation, const double& New_Value){
            Operation = New_Operation;
            Value = New_Value;
        }
        double Apply(double Source_value) const{
            if (Operation == '+'){
                return Source_value + Value;
            } else if (Operation == '-') {
                return Source_value - Value;
            } else if (Operation == '/') {
                return Source_value / Value;
            } else if (Operation == '*') {
                return Source_value * Value;
            }
            return 0;
        }
        void Invert(){
            if (Operation == '+'){
                Operation = '-';
            } else if (Operation == '-') {
                Operation = '+';
            } else if (Operation == '*'){
                Operation = '/';
            } else if (Operation == '/') {
                Operation = '*';
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