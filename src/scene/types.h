/*
 *  @file   Types.h
 *
 *  @brief  Self-explanatory enum to help identify Element type (Text, Audio, Image, etc)
 */

#pragma once

enum class EElementType
{
    None = 0,
    Text,
    Img,
    ImgSeq,
    Audio
};

const char* el_type_to_cstr(EElementType e);
std::string el_type_to_str(EElementType e);

