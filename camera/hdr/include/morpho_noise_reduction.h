//====================================================================
// morpho_noise_reduction.h
// [SJIS/CRLF] { �� �������������������p }
//
// Copyright(c) 2006-2012 Morpho,Inc.
//====================================================================

#ifndef MORPHO_NOISE_REDUCTION_H
# define MORPHO_NOISE_REDUCTION_H

//--------------------------------------------------------------------

# include "morpho_api.h"
# include "morpho_error.h"
# include "morpho_image_data.h"
# include "morpho_motion_data.h"
# include "morpho_rect_int.h"

//--------------------------------------------------------------------

# ifdef __cplusplus
extern "C" {
# endif

//====================================================================

/** �o�[�W���������� */
# define MORPHO_NOISE_REDUCTION_VERSION "Morpho Noise Reduction Ver.0.9.0 2012/08/09"

//--------------------------------------------------------------------
/** �m�C�Y������ */
typedef struct
{
    void *p; /**< ���\���̂ւ̃|�C���^ */
} morpho_NoiseReduction;

//--------------------------------------------------------------------

/**
 * �o�[�W�������������擾
 *
 * @return �o�[�W����������(MORPHO_IMAGE_STABILIZER_VERSION)
 */
MORPHO_API(const char *)
morpho_NoiseReduction_getVersion(void);

/**
 * �m�C�Y���������ɕK�v�ȃ������T�C�Y���擾
 * �w���ł����t�H�[�}�b�g��TRM���Q�ƁB
 *
 * @param[in] width  ���͉摜�̕�
 * @param[in] height ���͉摜�̍���
 * @param[in] format �摜�t�H�[�}�b�g������
 * @return �K�v�ȃ������T�C�Y(byte)
 */
MORPHO_API(int)
morpho_NoiseReduction_getBufferSize(
    int width,
    int height,
    const char *format);

/**
 * �m�C�Y�������̏�����
 *
 * @param[out] reducer  �m�C�Y������
 * @param[out] buffer      �m�C�Y�������Ɋ��蓖�Ă郁�����ւ̃|�C���^
 * @param[in]  buffer_size �m�C�Y�������Ɋ��蓖�Ă郁�����̃T�C�Y.
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_initialize(
    morpho_NoiseReduction *reducer,
    void *buffer,
    int buffer_size);

/**
 * �m�C�Y�������̃N���[���A�b�v
 *
 * @param[in,out] reducer �m�C�Y������
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_finalize(
    morpho_NoiseReduction *reducer);

/**
 * �m�C�Y��������: �����J�n
 * �o�͉摜(output_image)��1���ڂ̓��͉摜�Ɠ����ł��ǂ�
 *
 * @param[in,out] reducer    �m�C�Y������
 * @param[out]    output_image  �o�͉摜
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_start(
    morpho_NoiseReduction *reducer,
    morpho_ImageData *output_image);

/**
 * �m�C�Y��������: �m�C�Y����
 *
 * @param[in,out] reducer   �m�C�Y������
 * @param[out]    input_image  �o�͉摜
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_reduceNoise(
    morpho_NoiseReduction *reducer,
    morpho_ImageData *input_image);

/**
 * �摜�t�H�[�}�b�g���擾
 * initialize()��s���Ɏ擾�\
 * �o�b�t�@�T�C�Y��32�ȏ��Ƃ��邱��
 *
 * @param[in,out] reducer �m�C�Y������
 * @param[out] format �摜�t�H�[�}�b�g�����񂪊i�[������
 * @param[in] buffer_size �o�b�t�@�T�C�Y
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_getImageFormat(
    morpho_NoiseReduction *reducer,
    char *format,
    const int buffer_size);

/**
 * �P�x�m�C�Y�������x���x�����擾
 * initialize()��s���Ɏ擾�\
 *
 * @param[in,out] reducer �m�C�Y������
 * @param[out] level �P�x�m�C�Y�������x���x�����i�[������
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_getLumaNoiseReductionLevel(
    morpho_NoiseReduction *reducer,
    int *level);

/**
 * �N���}�m�C�Y�������x���x�����擾
 * initialize()��s���Ɏ擾�\
 *
 * @param[in,out] reducer �m�C�Y������
 * @param[out] level �N���}�m�C�Y�������x���x�����i�[������
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_getChromaNoiseReductionLevel(
    morpho_NoiseReduction *reducer,
    int *level);

/**
 * �摜�t�H�[�}�b�g���ݒ�
 * initialize()��s�ォ��start()��s�O�ɐݒ��\
 * �w���ł����t�H�[�}�b�g��TRM���Q�ƁB
 *
 * @param[in,out] reducer �m�C�Y������
 * @param[in] format �摜�t�H�[�}�b�g������
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_setImageFormat(
    morpho_NoiseReduction *reducer,
    const char *format);

/**
 * �P�x�m�C�Y�������x���x�����ݒ�
 * initialize()��s�ォ��start()��s�O�ɐݒ��\
 *
 * @param[in,out] reducer �m�C�Y������
 * @param[in] level �P�x�m�C�Y�������x���x��(0-7)
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_setLumaNoiseReductionLevel(
    morpho_NoiseReduction *reducer,
    int level);

/**
 * �N���}�m�C�Y�������x���x�����ݒ�
 * initialize()��s�ォ��start()��s�O�ɐݒ��\
 *
 * @param[in,out] reducer �m�C�Y������
 * @param[in] level �N���}�m�C�Y�������x���x��(0-7)
 * @return �G���[�R�[�h(morpho_error.h)
 */
MORPHO_API(int)
morpho_NoiseReduction_setChromaNoiseReductionLevel(
    morpho_NoiseReduction *reducer,
    int level);

//====================================================================

# ifdef __cplusplus
} // extern "C"
# endif

//--------------------------------------------------------------------

#endif // !MORPHO_IMAGE_STABILIZER3_H

//====================================================================
// [EOF]
