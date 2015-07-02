/*******************************************************************
 * morpho_hdr_checker.h
 * [CP932/CRLF] { �� �������������������p }
 *------------------------------------------------------------------
 * Copyright (C) 2011-2012 Morpho,Inc.
 *******************************************************************/

#ifndef MORPHO_HDR_CHECKER_H
#define MORPHO_HDR_CHECKER_H

/*******************************************************************/

#include "morpho_api.h"
#include "morpho_error.h"
#include "morpho_image_data.h"

/*******************************************************************/

#define MORPHO_HDR_CHECKER_VER "Morpho DR Checker Ver.1.1.0 2012/1/17"

/*-----------------------------------------------------------------*/

#define MORPHO_HDR_CHECKER_MIN_IMAGE_WIDTH     2
#define MORPHO_HDR_CHECKER_MAX_IMAGE_WIDTH  8192
#define MORPHO_HDR_CHECKER_MIN_IMAGE_HEIGHT    2
#define MORPHO_HDR_CHECKER_MAX_IMAGE_HEIGHT 8192

/*******************************************************************/

typedef struct _morpho_HDRChecker morpho_HDRChecker;

/* HDR�w�W�]���� */
struct _morpho_HDRChecker
{
    void *p; /**< ���\���̂ւ̃|�C���^ */
};

/* �����сE���Ԃꔻ���̕q���x */
typedef enum {
    MORPHO_HDR_CHECKER_SENSITIVITY_SENSITIVE,
    MORPHO_HDR_CHECKER_SENSITIVITY_NORMAL,
    MORPHO_HDR_CHECKER_SENSITIVITY_INSENSITIVE,
} MORPHO_HDR_CHECKER_SENSITIVITY;

/*******************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * �o�[�W�������������擾
 *
 * @return �o�[�W����������(MORPHO_EASY_HDR_VER)
 */
MORPHO_API(const char*)
morpho_HDRChecker_getVersion(void);

/**
 * �K�v�ȃ������T�C�Y���擾
 *
 * @param[in] width  ���͉摜�̕�
 * @param[in] height ���͉摜�̍���
 * @param[in] format ���͉摜�̃t�H�[�}�b�g
 * @return �K�v�ȃ������T�C�Y(byte)
 */
MORPHO_API(int)
morpho_HDRChecker_getBufferSize(
    int width,
    int height,
    const char *format);

/**
 * ������
 *
 * @param[in,out] p           HDRChecker�C���X�^���X
 * @param[in]     buffer      HDRChecker�Ɋ��蓖�Ă郁�����ւ̃|�C���^
 * @param[in]     buffer_size HDRChecker�Ɋ��蓖�Ă郁�����̃T�C�Y
 * @param[in]     width       ���͉摜�̕�
 * @param[in]     height      ���͉摜�̍���
 * @param[in]     format      ���͉摜�̃t�H�[�}�b�g
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_HDRChecker_initialize(
    morpho_HDRChecker * const p,
    void * const buffer,
    const int buffer_size,
    const int width,
    const int height,
    const char *format);

/**
 * �N���[���A�b�v
 * initialize()��s���Ɏ�s�\
 *
 * @param[in,out] p HDRChecker�C���X�^���X
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_HDRChecker_finalize(
    morpho_HDRChecker *p);

/*-----------------------------------------------------------------*/

/**
 * HDR�w�W�v�Z�̕q�����̐ݒ�
 * initialize()��s���Ɏ�s�\
 *
 * @param[in,out] p           HDRChecker�C���X�^���X
 * @param[in]     sensitivity �q����(MORPHO_HDR_CHECKER_SENSITIVIY�񋓑̂Ŏw��)
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_HDRChecker_setSensitivity(
    morpho_HDRChecker * const p,
    MORPHO_HDR_CHECKER_SENSITIVITY sensitivity);

/**
 * HDR�w�W�v�Z�̕q�����̎擾
 * initialize()��s���Ɏ�s�\
 *
 * @param[in,out] p           HDRChecker�C���X�^���X
 * @param[out]    sensitivity �q�����ւ̃|�C���^
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_HDRChecker_getSensitivity(
    morpho_HDRChecker * const p,
    MORPHO_HDR_CHECKER_SENSITIVITY *sensitivity);

/**
 * HDR�w�W�̕]��
 * initialize()��s���Ɏ�s�\
 *
 * @param[in,out] p      HDRChecker�C���X�^���X
 * @param[out]    result �]�����ʂ��i�[�����z��(�v�f��4�̔z��)
 *                       �v�f�����[���̏ꍇ�ɑΉ����鉺�L�̘I�o�̉摜���K�v�Ɣ���
 *                       {+2, +1, -1, -2}�̏��ɔ��茋�ʂ��i�[������
 * @param[in]     input_image ���͉摜
 * @return �G���[�R�[�h (see morpho_error.h)
 */
MORPHO_API(int)
morpho_HDRChecker_evaluate(
    morpho_HDRChecker * const p,
    int * const result,
    const morpho_ImageData * const input_image);

/*-----------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* MORPHO_HDR_CHECKER_H */
