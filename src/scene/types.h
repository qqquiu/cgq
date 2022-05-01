/*
 *  @file   types.h
 *
 *  @brief  Self-explanatory enum to help identify element types
 */

#pragma once

enum class EElementType
{
    NoType = 0,
    Text,
    Img,
    ImgSeq,
    Audio
};

const char* el_type_to_cstr(EElementType e);
std::string el_type_to_str(EElementType e);

