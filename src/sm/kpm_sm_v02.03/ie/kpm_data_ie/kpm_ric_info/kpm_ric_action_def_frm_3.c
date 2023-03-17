#include <assert.h>

#include "kpm_ric_action_def_frm_3.h"

void free_kpm_action_def_frm_3(kpm_act_def_format_3_t* src)
{
  assert(src != NULL);

  // Measurement Information
  // [1, 65535]
  for (size_t i = 0; i<src->meas_info_lst_len; i++)
  {
      free_meas_info_frm_3(&src->meas_info_lst[i]);
  }
  free(src->meas_info_lst);


  // Cell Global ID
  if (src->cell_global_id != NULL)
    free(src->cell_global_id);

}


bool eq_kpm_action_def_frm_3(kpm_act_def_format_3_t const * m0, kpm_act_def_format_3_t const * m1)
{
  assert(m0 != NULL);
  assert(m1 != NULL);

  // Measurement Information
  // [1, 65535]
  if (m0->meas_info_lst_len != m1->meas_info_lst_len)
    return false;

  for (size_t i = 0; i < m0->meas_info_lst_len; i++)
  {
    if (eq_meas_info_frm_3(&m0->meas_info_lst[i], &m1->meas_info_lst[i]) != true)
      return false;
  }


  // Granularity Period
  if (m0->gran_period_ms != m1->gran_period_ms)
    return false;

  // Cell Global ID
  if (m0->cell_global_id != NULL || m1->cell_global_id != NULL)
  {
    if (eq_cell_global_id(m0->cell_global_id, m1->cell_global_id) != true)
      return false;
  }


  return true;
}

kpm_act_def_format_3_t cp_kpm_action_def_frm_3(const kpm_act_def_format_3_t * src)
{
  assert(src != NULL);

  kpm_act_def_format_3_t dst = {0};

  // Measurement Information List Format 3
  dst.meas_info_lst_len = src->meas_info_lst_len;
    
  dst.meas_info_lst = calloc(src->meas_info_lst_len, sizeof(meas_info_format_3_lst_t));
  memcpy (dst.meas_info_lst, src->meas_info_lst, src->meas_info_lst_len * sizeof(meas_info_format_3_lst_t));
    
    
  for (size_t i = 0; i<dst.meas_info_lst_len; i++)
  {
    dst.meas_info_lst[i] = cp_meas_info_frm_3(&src->meas_info_lst[i]);
  }

  // Granularity Period - Mandatory
  dst.gran_period_ms = src->gran_period_ms;


  // Cell Global ID - Optional
  if (src->cell_global_id != NULL)
  {
    dst.cell_global_id = calloc(1, sizeof(cell_global_id_t));
    *dst.cell_global_id = cp_cell_global_id(&src->cell_global_id);
  }



  return dst;
}
