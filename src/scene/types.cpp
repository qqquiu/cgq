#include "pch.h"
#include "Types.h"

namespace CGQ
{
    const char* Type::ToCStr() const
    {
        switch (type)
        {
            case EType::None:   return "NO TYPE";
            case EType::Text:   return "TEXT";
            case EType::Img:    return "IMAGE";
            case EType::ImgSeq: return "IMAGE SEQUENCE";
            case EType::Audio:  return "AUDIO";
            default:            return "! UNDEFINED !";
        }
    }

    std::string Type::ToString() const
    {
        return std::string(ToCStr());
    }
}
