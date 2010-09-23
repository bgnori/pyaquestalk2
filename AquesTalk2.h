//////////////////////////////////////////////////////////////////////
/*!	@class	AquesTalk2

	@brief	��§�����������󥸥� AquesTalk2

  ���������󤫤鲻���ȷ��ǡ������������������
  ���ϲ����ȷ��ϡ�8HKz����ץ��, 16bit,��Υ��,WAV�ե����ޥå�


	@author	N.Yamazaki (Aquest)

	@date	2009/11/28	N.Yamazaki	Creation (from AuesTalk.h)
*/
//  COPYRIGHT (C) 2009 AQUEST CORP.
//////////////////////////////////////////////////////////////////////
#if !defined(_AQUESTALK2_H_)
#define _AQUESTALK2_H_
#ifdef __cplusplus
extern "C"{
#endif

#if defined(AQUESTALK2_EXPORTS)
#undef	DllExport
#define DllExport	__declspec( dllexport )
#else
#define DllExport
#endif

#if !(defined(WIN32)||defined(WINCE))
#define	__stdcall		// for Linux etc.
#endif

/////////////////////////////////////////////
//!	���������󤫤鲻���ȷ�������
//!	�����ȷ��ǡ������������ΰ���ݤ���롣
//!	�����ȷ��ǡ����β������ܴؿ��θƤӽФ�¦��AquesTalk_FreeWave()�ˤƹԤ�
//! @param	koe[in]		�����������SJIS NULL��ü��
//! @param	iSpeed[in]	ȯ��®�� [%] 50-300 �δ֤ǻ��� default:100
//!	@param	pSize[out]	�������������ǡ����Υ�����[byte]�ʥ��顼�ξ��ϥ��顼�����ɤ��֤��
//!	@param	phontDat[in]	phont�ǡ�������Ƭ���ɥ쥹����ꤷ�ޤ�������DLL�Υǥե����Phont���Ѥ���Ȥ��ϣ�����ꤷ�ޤ���
//!	@return	WAV�ե����ޥåȤβ����ǡ�������Ƭ���ɥ쥹�����顼����NULL���֤�
DllExport unsigned char * __stdcall AquesTalk2_Synthe(const char *koe, int iSpeed, int *pSize, void *phontDat);
//! @param	koe[in]		�����������EUC NULL��ü��
DllExport unsigned char * __stdcall AquesTalk2_Synthe_Euc(const char *koe, int iSpeed, int *pSize, void *phontDat);
//! @param	koe[in]		�����������UTF8 NULL��ü BOM�ϤĤ����ʤ���
DllExport unsigned char * __stdcall AquesTalk2_Synthe_Utf8(const char *koe, int iSpeed, int *pSize, void *phontDat);
//! @param	koe[in]		�����������UTF16 NULL��ü BOM��̵ͭ�����ʤ�������ǥ�����ϼ¹ԴĶ��˽�����
DllExport unsigned char * __stdcall AquesTalk2_Synthe_Utf16(const unsigned short *koe, int iSpeed, int *pSize, void *phontDat);
//! @param	koe[in]		����������ʥ��޻�ɽ�� NULL��ü��
DllExport unsigned char * __stdcall AquesTalk2_Synthe_Roman(const char *koe, int iSpeed, int *pSize, void *phontDat);

/////////////////////////////////////////////
//!	�����ǡ������ΰ����
//!	@param  wav[in]		AquesTalk_Synthe()���֤��줿���ɥ쥹�����
DllExport void __stdcall AquesTalk2_FreeWave(unsigned char *wav);

#ifdef __cplusplus
}
#endif
#endif // !defined(_AQUESTALK2_H_)
//  ----------------------------------------------------------------------
// !  Copyright AQUEST Corp. 2006- .  All Rights Reserved.                !
// !  An unpublished and CONFIDENTIAL work.  Reproduction, adaptation, or !
// !  translation without prior written permission is prohibited except   !
// !  as allowed under the copyright laws.                                !
//  ----------------------------------------------------------------------
