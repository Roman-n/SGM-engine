#include "stdafx.h"
#pragma hdrstop

#include "Blender_sunshafts.h"

CBlender_sunshafts::CBlender_sunshafts	()	{	description.CLS		= 0;	}
CBlender_sunshafts::~CBlender_sunshafts	()	{	}
 
void	CBlender_sunshafts::Compile(CBlender_Compile& C)
{
	IBlender::Compile		(C);
	
	switch (C.iElement)
	{
		case 0://mask generation
			C.r_Pass		("null",			"sgm_sunshafts_occlusion",	FALSE,	FALSE,	FALSE);
			C.r_Sampler_rtf	("s_position",		r2_RT_P);
			C.r_Sampler_clf	("s_image",			r2_RT_generic0);
			C.r_End			();
			break;
		case 1:	//blurring mask
			C.r_Pass		("null",			"sgm_sunshafts_blur",	FALSE,	FALSE,	FALSE);
			C.r_Sampler_clf	("s_sunshafts0",	r2_RT_sunshafts0);
			C.r_End			();
			break;
		case 2:	//calculate sunshafts
			C.r_Pass		("null",			"sgm_sunshafts_calculate",	FALSE,	FALSE,	FALSE);
			C.r_Sampler_clf	("s_sunshafts1",	r2_RT_sunshafts1);
			C.r_End			();
			break;
		case 3:	//combine color
			C.r_Pass		("null",			"sgm_sunshafts_combine",	FALSE,	FALSE,	FALSE);
			C.r_Sampler_clf	("s_image",			r2_RT_generic0);
			C.r_Sampler_clf	("s_sunshafts2",	r2_RT_sunshafts2);
			C.r_End			();
			break;
	}
}