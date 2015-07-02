/**
 * @file     morpho_error.h
 * @brief    �G���[�R�[�h�̒��`
 * @version  1.0.0
 * @date     2008-06-09
 *
 * Copyright (C) 2006-2012 Morpho, Inc.
 */

#ifndef MORPHO_ERROR_H
#define MORPHO_ERROR_H

/** �G���[�R�[�h .*/
#define MORPHO_OK                   (0x00000000)  /**< ���� */
#define MORPHO_DOPROCESS            (0x00000001)  /**< ������ */
#define MORPHO_CANCELED             (0x00000002)  /**< �L�����Z�����ꂽ */
#define MORPHO_SUSPENDED            (0x00000008)  /**< ���f���ꂽ */

#define MORPHO_ERROR_GENERAL_ERROR  (0x80000000)  /**< ���ʓI�ȃG���[. */
#define MORPHO_ERROR_PARAM          (0x80000001)  /**< �������s��. */
#define MORPHO_ERROR_STATE          (0x80000002)  /**< �����Ԃ��֐��ďo�������s��. */
#define MORPHO_ERROR_MALLOC         (0x80000004)  /**< �������A���P�[�V�����G���[. */
#define MORPHO_ERROR_IO             (0x80000008)  /**< ���o�̓G���[. */
#define MORPHO_ERROR_UNSUPPORTED    (0x80000010)  /**< �@�\���T�|�[�g���Ă��Ȃ�. */
#define MORPHO_ERROR_NOTFOUND       (0x80000020)  /**< �����Ώۂ��������Ȃ� */
#define MORPHO_ERROR_INTERNAL       (0x80000040)  /**< ���G���[. */
#define MORPHO_ERROR_UNKNOWN        (0xC0000000)  /**< ���L�ȊO�̃G���[. */

#endif /* #ifndef MORPHO_ERROR_H */
