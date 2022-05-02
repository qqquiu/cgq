#include "pch.h"
#include "types.h"

const char* el_type_to_cstr(EElementType e)
{
    switch (e)
    {
    case EElementType::None: return "NO TYPE";
    case EElementType::Text: return "TEXT";
    case EElementType::Img: return "IMAGE";
    case EElementType::ImgSeq: return "IMAGE SEQUENCE";
    case EElementType::Audio: return "AUDIO";
    default: return "! UNDEFINED !";
    }
}

std::string el_type_to_str(EElementType e)
{
    return std::string(el_type_to_cstr(e));
}
