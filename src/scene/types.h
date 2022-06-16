/*
 *  @file   Types.h
 *
 *  @brief  Self-explanatory enum to help identify Element type (Text, Audio, Image, etc)
 */

#pragma once

namespace CGQ
{
    class Type
    {
    public:
        enum class EType : uint8_t
        {
            None = 0,
            Text,
            Img,
            ImgSeq,
            Audio
        };

        Type() = delete;
        constexpr Type(EType el_type) : type(el_type) { }

        const char* ToCStr() const;
        std::string ToString() const;
        //EType GetType() const;

    private:
        EType type;
    };
}