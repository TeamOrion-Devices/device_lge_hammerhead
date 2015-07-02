/**
 * @file     morpho_get_image_size.h
 * @brief    �摜�ɕK�v�ȃ������T�C�Y���擾�����֐�
 * @version  1.0.0
 * @date     2008-07-01
 *
 * Copyright (C) 2006-2012 Morpho, Inc.
 */

#ifndef MORPHO_GET_IMAGE_SIZE_H
#define MORPHO_GET_IMAGE_SIZE_H

#include "morpho_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * ���ƍ����ƃt�H�[�}�b�g�������A�摜���i�[�����̂ɕK�v�ȃ������T�C�Y�𓾂�.
 *
 * @param width       ��
 * @param height      ����
 * @param p_format    �摜�t�H�[�}�b�g������
 * @return            �摜�ɕK�v�ȃ������T�C�Y
 */
#define morpho_getImageSize mor_noise_reduction_IF_getImageSize

MORPHO_API(int)
morpho_getImageSize(int width, int height, const char *p_format);

/**
 * Y�摜�f�[�^�T�C�Y���擾.
 *
 * @param width       ��
 * @param height      ����
 * @param p_format    �摜�t�H�[�}�b�g������
 * @return            Y�摜�f�[�^�T�C�Y
 */
#define morpho_getImageSizeY mor_noise_reduction_IF_getImageSizeY

MORPHO_API(int)
morpho_getImageSizeY(int width, int height, const char *p_format);

/**
 * U�摜�f�[�^�T�C�Y���擾.
 *
 * @param width       ��
 * @param height      ����
 * @param p_format    �摜�t�H�[�}�b�g������
 * @return            U�摜�f�[�^�T�C�Y
 */
#define morpho_getImageSizeU mor_noise_reduction_IF_getImageSizeU

MORPHO_API(int)
morpho_getImageSizeU(int width, int height, const char *p_format);

/**
 * V�摜�f�[�^�T�C�Y���擾.
 *
 * @param width       ��
 * @param height      ����
 * @param p_format    �摜�t�H�[�}�b�g������
 * @return            V�摜�f�[�^�T�C�Y
 */
#define morpho_getImageSizeV mor_noise_reduction_IF_getImageSizeV

MORPHO_API(int)
morpho_getImageSizeV(int width, int height, const char *p_format);

/**
 * UV�摜�f�[�^�T�C�Y���擾.
 *
 * @param width       ��
 * @param height      ����
 * @param p_format    �摜�t�H�[�}�b�g������
 * @return            UV�摜�f�[�^�T�C�Y
 */
#define morpho_getImageSizeUV mor_noise_reduction_IF_getImageSizeUV

MORPHO_API(int)
morpho_getImageSizeUV(int width, int height, const char *p_format);


#ifdef __cplusplus
} /* extern "C" { */
#endif

#endif /* MORPHO_GET_IMAGE_SIZE_H */
