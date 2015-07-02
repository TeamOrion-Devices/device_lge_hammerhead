/**
 * @file     morpho_motion_data.h
 * @brief    �����f�[�^�̍\���̒��`
 * @version  1.0.0
 * @date     2008-06-09
 *
 * Copyright (C) 2006-2012 Morpho, Inc.
 */

#ifndef MORPHO_MOTION_DATA_H
#define MORPHO_MOTION_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

/** �����f�[�^. */
typedef struct {
    int v[6];  /**< �����f�[�^ */
    int fcode; /**< ����:0 / ���s:0�ȊO�i���s���������j */
} morpho_MotionData;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MORPHO_MOTION_DATA_H */
