/**
 * @file     morpho_image_data.h
 * @brief    �摜�f�[�^�̍\���̒��`
 * @version  1.0.0
 * @date     2008-06-09
 *
 * Copyright (C) 2006-2012 Morpho, Inc.
 */

#ifndef MORPHO_IMAGE_DATA_H
#define MORPHO_IMAGE_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
    void * y;               /**< Y�摜�̐擪�|�C���^ */
    void * u;               /**< U�摜�̐擪�|�C���^ */
    void * v;               /**< V�摜�̐擪�|�C���^ */
} morpho_ImageYuvPlanar;

typedef struct{
    void * y;               /**< Y�摜�̐擪�|�C���^ */
    void * uv;              /**< UV�摜�̐擪�|�C���^ */
} morpho_ImageYuvSemiPlanar;

/** �摜�f�[�^. */
typedef struct {
    int width;              /**< �� */
    int height;             /**< ���� */
    union{
        void * p;           /**< �摜�f�[�^�̐擪�|�C���^ */
        morpho_ImageYuvPlanar planar;
        morpho_ImageYuvSemiPlanar semi_planar;
    } dat;
} morpho_ImageData;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MORPHO_IMAGE_DATA_H */
