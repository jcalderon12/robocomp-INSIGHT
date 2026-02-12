// Definimos una estructura base por defecto
template<typename T> struct DSRTypeTrait;


// ENUM


// Especializamos para cada tipo que soportes
// Esto NO ocupa memoria en runtime, es solo información para el compilador.
template<> struct DSRTypeTrait<std::string>             { static constexpr const char* code = "s"; };
template<> struct DSRTypeTrait<int32_t>                 { static constexpr const char* code = "i"; };
template<> struct DSRTypeTrait<float>                   { static constexpr const char* code = "f"; };
template<> struct DSRTypeTrait<std::vector<float>>      { static constexpr const char* code = "vf"; };
template<> struct DSRTypeTrait<bool>                    { static constexpr const char* code = "b"; };
template<> struct DSRTypeTrait<std::vector<uint8_t>>    { static constexpr const char* code = "vc"; };
template<> struct DSRTypeTrait<uint32_t>                { static constexpr const char* code = "ui"; };
template<> struct DSRTypeTrait<uint64_t>                { static constexpr const char* code = "ui64"; };
template<> struct DSRTypeTrait<double>                  { static constexpr const char* code = "d"; };
template<> struct DSRTypeTrait<std::vector<uint64_t>>   { static constexpr const char* code = "vui64"; };
template<> struct DSRTypeTrait<std::array<float, 2>>    { static constexpr const char* code = "v2"; };
template<> struct DSRTypeTrait<std::array<float, 3>>    { static constexpr const char* code = "v3"; };
template<> struct DSRTypeTrait<std::array<float, 4>>    { static constexpr const char* code = "v4"; };
template<> struct DSRTypeTrait<std::array<float, 6>>    { static constexpr const char* code = "v6"; };


template <typename T>
std::vector<T> string_to_vec(std::string s) {
    std::vector<T> vec;
    s.erase(std::remove(s.begin(), s.end(), '['), s.end());
    s.erase(std::remove(s.begin(), s.end(), ']'), s.end());
    
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, ',')) {
        if (!item.empty()) {
            if constexpr (std::is_same_v<T, float>) vec.push_back(std::stof(item));
            else if constexpr (std::is_same_v<T, int>) vec.push_back(std::stoi(item));
            // Añadir más tipos si es necesario
        }
    }
    return vec;
}