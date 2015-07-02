/**
 * @file     morpho_rect_int.h
 * @brief    ���`�f�[�^�̍\���̒��`
 * @version  1.0.0
 * @date     2008-06-09
 *
 * Copyright (C) 2006-2012 Morpho, Inc.
 */

#ifndef MORPHO_RECT_INT_H
#define MORPHO_RECT_INT_H

#ifdef __cplusplus
extern "C" {
#endif

/** ���`�f�[�^. */
typedef struct {
    int sx; /**< left */
    int sy; /**< top */
    int ex; /**< right */
    int ey; /**< bottom */
} morpho_RectInt;

/** ���`�̈� rect �̍�����W (l,t) �ƉE����W (r,b) ���ݒ肷��. */
#define morpho_RectInt_setRect(rect,l,t,r,b) do { \
	(rect)->sx=(l);\
	(rect)->sy=(t);\
	(rect)->ex=(r);\
	(rect)->ey=(b);\
    } while(0)

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MORPHO_RECT_INT_H */
