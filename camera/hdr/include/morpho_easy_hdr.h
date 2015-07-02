/*******************************************************************
 * morpho_easy_hdr.h
 * [CP932/CRLF] { �� �������������������p }
 *------------------------------------------------------------------
 * Copyright (C) 2010-2012 Morpho,Inc.
 *******************************************************************/

#ifndef MORPHO_EASY_HDR_H
#define MORPHO_EASY_HDR_H

/*******************************************************************/

#include "morpho_api.h"
#include "morpho_error.h"
#include "morpho_image_data.h"
#include "morpho_rect_int.h"

/*******************************************************************/

#define MORPHO_EASY_HDR_VER "Morpho EasyHDR Ver.2.0.1 2012/07/18"

/*-----------------------------------------------------------------*/

/* (input-limitaion) */

#define MORPHO_EASY_HDR_MIN_IMAGE_WIDTH    100
#define MORPHO_EASY_HDR_MAX_IMAGE_WIDTH   8192
#define MORPHO_EASY_HDR_MIN_IMAGE_HEIGHT   100
#define MORPHO_EASY_HDR_MAX_IMAGE_HEIGHT  8192
#define MORPHO_EASY_HDR_MIN_NIMAGES   2
#define MORPHO_EASY_HDR_MAX_NIMAGES  10

/*-----------------------------------------------------------------*/

/* (parameter) */

#define MORPHO_EASY_HDR_DISABLED 0
#define MORPHO_EASY_HDR_ENABLED  1

#define MORPHO_EASY_HDR_IMAGE_ALIGNMENT_DEFAULT  MORPHO_EASY_HDR_ENABLED

#define MORPHO_EASY_HDR_GHOST_REMOVAL_DEFAULT  MORPHO_EASY_HDR_ENABLED

#define MORPHO_EASY_HDR_AUTO_SCALING_DEFAULT  MORPHO_EASY_HDR_ENABLED

#define MORPHO_EASY_HDR_FACE_DETECTION_DEFAULT  MORPHO_EASY_HDR_ENABLED

#define MORPHO_EASY_HDR_FAIL_SOFT_MERGING_DEFAULT  MORPHO_EASY_HDR_ENABLED

#define MORPHO_EASY_HDR_GHOST_DETECTION_SENSITIVITY_LEVEL_MIN      0
#define MORPHO_EASY_HDR_GHOST_DETECTION_SENSITIVITY_LEVEL_MAX     10
#define MORPHO_EASY_HDR_GHOST_DETECTION_SENSITIVITY_LEVEL_DEFAULT  7

#define MORPHO_EASY_HDR_MERGE_SMOOTHNESS_LEVEL_MIN      0
#define MORPHO_EASY_HDR_MERGE_SMOOTHNESS_LEVEL_MAX     10
#define MORPHO_EASY_HDR_MERGE_SMOOTHNESS_LEVEL_DEFAULT  6

#define MORPHO_EASY_HDR_MERGE_PARAM_MIN        0
#define MORPHO_EASY_HDR_MERGE_PARAM_MAX      255
#define MORPHO_EASY_HDR_MERGE_PARAM1_DEFAULT   0
#define MORPHO_EASY_HDR_MERGE_PARAM2_DEFAULT 128
#define MORPHO_EASY_HDR_MERGE_PARAM3_DEFAULT   0
#define MORPHO_EASY_HDR_MERGE_PARAM4_DEFAULT 255

#define MORPHO_EASY_HDR_RELIABLE_RECT_RATE_THRESHOLD_MIN       0
#define MORPHO_EASY_HDR_RELIABLE_RECT_RATE_THRESHOLD_MAX     100
#define MORPHO_EASY_HDR_RELIABLE_RECT_RATE_THRESHOLD_DEFAULT  80

#define MORPHO_EASY_HDR_GHOST_RATE_THRESHOLD_MIN       0
#define MORPHO_EASY_HDR_GHOST_RATE_THRESHOLD_MAX     100
#define MORPHO_EASY_HDR_GHOST_RATE_THRESHOLD_DEFAULT  90

#define MORPHO_EASY_HDR_CC_OFFSET_MIN          0
#define MORPHO_EASY_HDR_CC_OFFSET_MAX        255
#define MORPHO_EASY_HDR_CC_Y_OFFSET_DEFAULT    0
#define MORPHO_EASY_HDR_CC_C_OFFSET_DEFAULT    0

#define MORPHO_EASY_HDR_CC_GAIN_MIN        100
#define MORPHO_EASY_HDR_CC_GAIN_MAX       2000
#define MORPHO_EASY_HDR_CC_Y_GAIN_DEFAULT 1000
#define MORPHO_EASY_HDR_CC_C_GAIN_DEFAULT 1000

#define MORPHO_EASY_HDR_CC_GAMMA_MIN        100
#define MORPHO_EASY_HDR_CC_GAMMA_MAX       2000
#define MORPHO_EASY_HDR_CC_Y_GAMMA_DEFAULT 1000
#define MORPHO_EASY_HDR_CC_C_GAMMA_DEFAULT 1000

/*-----------------------------------------------------------------*/

/* (merge-status) */

#define MORPHO_EASY_HDR_OK                             0x00000000
#define MORPHO_EASY_HDR_ERROR_IMAGE_ALIGNMENT_FAILURE  0x00000001
#define MORPHO_EASY_HDR_ERROR_EXP_ESTIMATION_FAILURE   0x00000002
#define MORPHO_EASY_HDR_ERROR_MOSTLY_GHOST             0x00000004
#define MORPHO_EASY_HDR_ERROR_INTERNAL                 0x80000000

/*******************************************************************/

typedef struct _morpho_EasyHDR morpho_EasyHDR;
typedef struct _morpho_EasyHDR_Callback morpho_EasyHDR_Callback;

/*-----------------------------------------------------------------*/

/** EasyHDR */
struct _morpho_EasyHDR
{
    void *p; /**< ���\���̂ւ̃|�C���^ */
};

/** EasyHDR Callback (for multi-thread processing) */
struct _morpho_EasyHDR_Callback
{
    void *p; /**< �R�[���o�b�N�֐��̑��������Ƃ��ēn�������l */

    void * (* thread_create )(void *p, int index, void *(*start_routine)(void *arg), void *arg);
    int    (* thread_destroy)(void *p, void *thread);
    int    (* thread_join   )(void *p, void *thread, void **value_ptr);

    void * (* mutex_create )(void *p);
    int    (* mutex_destroy)(void *p, void *mutex);
    int    (* mutex_lock   )(void *p, void *mutex);
    int    (* mutex_trylock)(void *p, void *mutex);
    int    (* mutex_unlock )(void *p, void *mutex);

    void * (* cond_create   )(void *p);
    int    (* cond_destroy  )(void *p, void *cond);
    int    (* cond_wait     )(void *p, void *cond, void *lock);
    int    (* cond_signal   )(void *p, void *cond);
    int    (* cond_broadcast)(void *p, void *cond);
};

/*******************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------------------*/

/**
 * �o�[�W�������������擾
 *
 * @return �o�[�W����������(MORPHO_EASY_HDR_VER)
 */
MORPHO_API(char const *)
morpho_EasyHDR_getVersion(void);

/*-----------------------------------------------------------------*/

/**
 * �K�v�ȃ������T�C�Y���擾
 *
 * @param[in]  max_width   ���͉摜�̍ő啝
 * @param[in]  max_height  ���͉摜�̍ő卂��
 * @param[in]  format      �摜�t�H�[�}�b�g������
 *
 * @return �K�v�ȃ������T�C�Y(byte)
 */
MORPHO_API(int)
morpho_EasyHDR_getBufferSize(
    int max_width,
    int max_height,
    char const *format);

/**
 * ������
 *
 * �g�p�X���b�h����0�ȉ��̒l���ݒ肵���ꍇ�A
 * ������s���s���B
 *
 * �g�p�X���b�h����1�ȏ��̒l���ݒ肵���ꍇ�A
 * �ꊇ��s���s���B
 *
 * �g�p�X���b�h����2�ȏ��̒l���ݒ肵���ꍇ�A
 * �}���`�X���b�h�ɂ��������s(�ꊇ��s)���s���B
 * callback �ɓK�؂Ȓl���ݒ肷���K�v�����B
 *
 * �y��s���Ԃ̑J�ځz
 *     ?_UNKNOWN �� 0_INITIALIZED
 *
 * @param[in,out]  p            EasyHDR �C���X�^���X
 * @param[out]     buffer       EasyHDR�Ɋ��蓖�Ă郁�����ւ̃|�C���^
 * @param[in]      buffer_size  EasyHDR�Ɋ��蓖�Ă郁�����̃T�C�Y
 * @param[in]      nthreads     �g�p�X���b�h�� (�R�A��)
 * @param[in]      callback     �R�[���o�b�N�֐��Q
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_initialize(
    morpho_EasyHDR *p,
    void *buffer,
    int buffer_size,
    int nthreads,
    morpho_EasyHDR_Callback const *callback);

/**
 * �N���[���A�b�v
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p  EasyHDR �C���X�^���X
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_finalize(
    morpho_EasyHDR *p);

/*-----------------------------------------------------------------*/

/**
 * �����̊J�n�E��s
 * setImageFormat() ��s���Ɏ�s�\
 *
 * �y��s���Ԃ̑J�� (�ꊇ��s��)�z
 *     0_INITIALIZED �� (1_PROCESSING) �� 0_INITIALIZED (��������)
 *                                     �� 2_SUSPENDED   (suspend()�Ăяo��)
 *
 * �y��s���Ԃ̑J�� (������s��)�z
 *     0_INITIALIZED �� 3_PAUSED      (������)
 *                   �� 0_INITIALIZED (��������)
 *
 * @param[in,out]  p             EasyHDR �C���X�^���X
 * @param[out]     output_image  ���ʉ摜 (�u1���ځv�̓��͉摜���w���\)
 * @param[in,out]  input_images  ���͉摜�Q (�G���W���ɂ���ď�������������)
 * @param[in]      nimages       ���͉摜�̐�
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_merge(
    morpho_EasyHDR *p,
    morpho_ImageData *output_image,
    morpho_ImageData *input_images[],
    int nimages);

/*-----------------------------------------------------------------*/

/**
 * �����̌p����s
 *
 * merge() ��s���Ɏ�s�\
 *
 * ������s��(initialize() �� nthreads �� 0 ���w�肵���Ƃ�)�̂ݗL��
 *
 * �y��s���Ԃ̑J�� (������s��)�z
 *     3_PAUSED �� 3_PAUSED      (������)
 *              �� 0_INITIALIZED (��������)
 *
 * @param[in,out]  p  EasyHDR �C���X�^���X
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_process(
    morpho_EasyHDR *p);

/*-----------------------------------------------------------------*/

/**
 * �����̒��f (�ʃR���e�L�X�g�����̌Ăяo���ɂ���)
 * merge() ��s���Ɏ�s�\
 *
 * �y��s���Ԃ̑J�� (�ꊇ��s��)�z
 *     1_PROCESSING �� 2_SUSPENDED
 *
 * @param[in,out]  p  EasyHDR �C���X�^���X
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_suspend(
    morpho_EasyHDR *p);

/**
 * �����̍ĊJ
 * suspend() ��s���Ɏ�s�\
 *
 * �y��s���Ԃ̑J�� (�ꊇ��s��)�z
 *     2_SUSPENDED �� (1_PROCESSING) �� 0_INITIALIZED (��������)
 *                                   �� 2_SUSPENDED   (suspend()�Ăяo��)
 *
 * @param[in,out]  p  EasyHDR �C���X�^���X
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_resume(
    morpho_EasyHDR *p);

/*-----------------------------------------------------------------*/

/**
 * �摜�t�H�[�}�b�g�̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p       EasyHDR �C���X�^���X
 * @param[in]      format  �摜�t�H�[�}�b�g����킷������
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setImageFormat(
    morpho_EasyHDR *p,
    char const *format);

/**
 * �摜�t�H�[�}�b�g�̎擾
 * setImageFormat() ��s���Ɏ�s�\
 *
 * @param[in,out]  p            EasyHDR �C���X�^���X
 * @param[out]     buffer       �摜�t�H�[�}�b�g����킷�����񂪊i�[�������o�b�t�@
 * @param[in]      buffer_size  �o�b�t�@�̃T�C�Y(�I�[�����܂�)
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getImageFormat(
    morpho_EasyHDR *p,
    char *buffer,
    int buffer_size);

/*-----------------------------------------------------------------*/

/**
 * �ʒu���킹(���Ԃ��␳)�̗L���̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * value:
 *   MOR_EASY_HDR_ENABLED  : �ʒu���킹����
 *   MOR_EASY_HDR_DISABLED : �ʒu���킹�Ȃ�
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[in]      value  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setImageAlignmentStatus(
    morpho_EasyHDR *p,
    int value);

/**
 * �ʒu���킹(���Ԃ��␳)�̗L���̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[out]     value  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getImageAlignmentStatus(
    morpho_EasyHDR *p,
    int *value);

/*-----------------------------------------------------------------*/

/**
 * �S�[�X�g����(���ʑ̂Ԃ��␳)�̗L���̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * value:
 *   MOR_EASY_HDR_ENABLED  : �S�[�X�g��������
 *   MOR_EASY_HDR_DISABLED : �S�[�X�g�����Ȃ�
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[in]      value  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setGhostRemovalStatus(
    morpho_EasyHDR *p,
    int value);

/**
 * �S�[�X�g����(���ʑ̂Ԃ��␳)�̗L���̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[out]     value  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getGhostRemovalStatus(
    morpho_EasyHDR *p,
    int *value);

/*-----------------------------------------------------------------*/

/**
 * �����g��(�N���b�s���O)�̗L���̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * value:
 *   MOR_EASY_HDR_ENABLED  : �����g�傠��
 *   MOR_EASY_HDR_DISABLED : �����g���Ȃ�
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[in]      value  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setAutoScalingStatus(
    morpho_EasyHDR *p,
    int value);

/**
 * �����g��(�N���b�s���O)�̗L���̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[out]     value  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getAutoScalingStatus(
    morpho_EasyHDR *p,
    int *value);

/*-----------------------------------------------------------------*/

/**
 * �猟�o�␳�̗L���̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * value:
 *   MOR_EASY_HDR_ENABLED  : �猟�o�␳����
 *   MOR_EASY_HDR_DISABLED : �猟�o�␳�Ȃ�
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[in]      value  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setFaceDetectionStatus(
    morpho_EasyHDR *p,
    int value);

/**
 * �猟�o�␳�̗L���̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[out]     value  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getFaceDetectionStatus(
    morpho_EasyHDR *p,
    int *value);

/*-----------------------------------------------------------------*/

/**
 * Fail-soft-merging �̗L���̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * value:
 *   MOR_EASY_HDR_ENABLED  : Fail-soft-merging ����
 *   MOR_EASY_HDR_DISABLED : Fail-soft-merging �Ȃ�
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[in]      value  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setFailSoftMergingStatus(
    morpho_EasyHDR *p,
    int value);

/**
 * Fail-soft-merging �̗L���̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[out]     value  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getFailSoftMergingStatus(
    morpho_EasyHDR *p,
    int *value);

/*-----------------------------------------------------------------*/

/**
 * �S�[�X�g���芴�x���x���̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[in]      value  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setGhostDetectionSensitivityLevel(
    morpho_EasyHDR *p,
    int value);

/**
 * �S�[�X�g���芴�x���x���̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[out]     value  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getGhostDetectionSensitivityLevel(
    morpho_EasyHDR *p,
    int *value);

/*-----------------------------------------------------------------*/

/**
 * �����Ȃ߂炩���̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[in]      value  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setMergeSmoothnessLevel(
    morpho_EasyHDR *p,
    int value);

/**
 * �����Ȃ߂炩���̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p      EasyHDR �C���X�^���X
 * @param[out]     value  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getMergeSmoothnessLevel(
    morpho_EasyHDR *p,
    int *value);

/*-----------------------------------------------------------------*/

/**
 * �����p�����[�^�̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p       EasyHDR �C���X�^���X
 * @param[in]      value1  �ݒ��l
 * @param[in]      value2  �ݒ��l
 * @param[in]      value3  �ݒ��l
 * @param[in]      value4  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setMergeParameters(
    morpho_EasyHDR *p,
    int value1,
    int value2,
    int value3,
    int value4);

/**
 * �����p�����[�^�̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p       EasyHDR �C���X�^���X
 * @param[out]     value1  �ݒ��l�i�[��
 * @param[out]     value2  �ݒ��l�i�[��
 * @param[out]     value3  �ݒ��l�i�[��
 * @param[out]     value4  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getMergeParameters(
    morpho_EasyHDR *p,
    int *value1,
    int *value2,
    int *value3,
    int *value4);

/*-----------------------------------------------------------------*/

/**
 * �L���̈�臒l�̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p     EasyHDR �C���X�^���X
 * @param[in]      rate  �ݒ��l (���� rate % ���`)
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setReliableRectRateThreshold(
    morpho_EasyHDR *p,
    int rate);

/**
 * �L���̈�臒l�̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p     EasyHDR �C���X�^���X
 * @param[out]     rate  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getReliableRectRateThreshold(
    morpho_EasyHDR *p,
    int *rate);

/**
 * �L���̈��̎擾
 * initialize() ��s���Ɏ�s�\
 * (�L���Ȓl���Z�b�g�������̂� merge() ��)
 *
 * @param[in,out]  p     EasyHDR �C���X�^���X
 * @param[out]     rect  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getReliableRect(
    morpho_EasyHDR *p,
    morpho_RectInt *rect);

/*-----------------------------------------------------------------*/

/**
 * �S�[�X�g����臒l�̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p     EasyHDR �C���X�^���X
 * @param[in]      rate  �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setGhostRateThreshold(
    morpho_EasyHDR *p,
    int rate);

/**
 * �S�[�X�g����臒l�̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p     EasyHDR �C���X�^���X
 * @param[out]     rate  �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getGhostRateThreshold(
    morpho_EasyHDR *p,
    int *rate);

/*-----------------------------------------------------------------*/

/**
 * �F�␳�p�����[�^�̐ݒ�
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p         EasyHDR �C���X�^���X
 * @param[in]      y_offset  �ݒ��l
 * @param[in]      y_gain    �ݒ��l
 * @param[in]      y_gamma   �ݒ��l
 * @param[in]      c_offset  �ݒ��l
 * @param[in]      c_gain    �ݒ��l
 * @param[in]      c_gamma   �ݒ��l
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_setColorCorrectionParameters(
    morpho_EasyHDR *p,
    int y_offset,
    int y_gain,
    int y_gamma,
    int c_offset,
    int c_gain,
    int c_gamma);

/**
 * �F�␳�p�����[�^�̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * @param[in,out]  p         EasyHDR �C���X�^���X
 * @param[out]     y_offset  �ݒ��l�i�[��
 * @param[out]     y_gain    �ݒ��l�i�[��
 * @param[out]     y_gamma   �ݒ��l�i�[��
 * @param[out]     c_offset  �ݒ��l�i�[��
 * @param[out]     c_gain    �ݒ��l�i�[��
 * @param[out]     c_gamma   �ݒ��l�i�[��
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_getColorCorrectionParameters(
    morpho_EasyHDR *p,
    int *y_offset,
    int *y_gain,
    int *y_gamma,
    int *c_offset,
    int *c_gain,
    int *c_gamma);

/*-----------------------------------------------------------------*/

/**
 * �����X�e�[�^�X�̎擾
 * initialize() ��s���Ɏ�s�\
 *
 * �X�e�[�^�X�R�[�h
 *   MORPHO_EASY_HDR_OK
 *   MORPHO_EASY_HDR_ERROR_*
 *
 * @param[in,out]  p  EasyHDR �C���X�^���X
 *
 * @return �X�e�[�^�X�R�[�h (MORPHO_EASMORPHO_EASY_HDR_ERROR_
 */
MORPHO_API(int)
morpho_EasyHDR_getMergeStatus(
    morpho_EasyHDR *p);

/*-----------------------------------------------------------------*/

/**
 * �T���l�C���̍쐬 (�o�͉摜�̏k��)
 * morpho_EasyHDR_setImageFormat() ��s���Ɏ�s�\
 *
 * @param[in,out]  p                EasyHDR �C���X�^���X
 * @param[out]     thumbnail_image  �o�͉摜
 * @param[in]      output_image     ���͉摜
 *
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_EasyHDR_makeThumbnail(
    morpho_EasyHDR *p,
    morpho_ImageData *thumbnail_image,
    morpho_ImageData const *output_image);

/*-----------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/*******************************************************************/

#endif /* !MORPHO_EASY_HDR_H */

/*******************************************************************/
/* [EOF] */
