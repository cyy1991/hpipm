/**************************************************************************************************
*                                                                                                 *
* This file is part of HPIPM.                                                                     *
*                                                                                                 *
* HPIPM -- High Performance Interior Point Method.                                                *
* Copyright (C) 2017 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* HPIPM is free software; you can redistribute it and/or                                          *
* modify it under the terms of the GNU Lesser General Public                                      *
* License as published by the Free Software Foundation; either                                    *
* version 2.1 of the License, or (at your option) any later version.                              *
*                                                                                                 *
* HPIPM is distributed in the hope that it will be useful,                                        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                            *
* See the GNU Lesser General Public License for more details.                                     *
*                                                                                                 *
* You should have received a copy of the GNU Lesser General Public                                *
* License along with HPIPM; if not, write to the Free Software                                    *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA                  *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/



#include <blasfeo_target.h>
#include <blasfeo_common.h>




struct s_tree_ocp_qp_ipm_workspace
	{
	struct s_core_qp_ipm_workspace *core_workspace;
	struct s_strvec *dux;
	struct s_strvec *dpi;
	struct s_strvec *dt;
	struct s_strvec *res_g; // q-residuals
	struct s_strvec *res_b; // b-residuals
	struct s_strvec *res_d; // d-residuals XXX remove ???
	struct s_strvec *res_m; // m-residuals
	struct s_strvec *Gamma; // hessian update
	struct s_strvec *gamma; // hessian update
	struct s_strvec *tmp_nxM; // work space of size nxM
	struct s_strvec *tmp_nbgM; // work space of size nbgM
	struct s_strvec *tmp_nsM; // work space of size nsM
	struct s_strvec *Pb; // Pb
	struct s_strvec *Zs_inv;
	struct s_strmat *L;
	struct s_strmat *AL;
	float *stat; // convergence statistics
	float res_mu; // mu-residual
	int iter; // iteration number
	int memsize;
	};



struct s_tree_ocp_qp_ipm_arg
	{
	float alpha_min; // exit cond on step length
	float mu_max; // exit cond on duality measure
	float mu0; // initial value for duality measure
	int iter_max; // exit cond in iter number
	};



//
int s_memsize_tree_ocp_qp_ipm(struct s_tree_ocp_qp *qp, struct s_tree_ocp_qp_ipm_arg *arg);
//
void s_create_tree_ocp_qp_ipm(struct s_tree_ocp_qp *qp, struct s_tree_ocp_qp_ipm_arg *arg, struct s_tree_ocp_qp_ipm_workspace *ws, void *mem);
//
void s_solve_tree_ocp_qp_ipm(struct s_tree_ocp_qp *qp, struct s_tree_ocp_qp_sol *qp_sol, struct s_tree_ocp_qp_ipm_workspace *ws);
//
void s_solve_tree_ocp_qp_ipm2(struct s_tree_ocp_qp *qp, struct s_tree_ocp_qp_sol *qp_sol, struct s_tree_ocp_qp_ipm_workspace *ws);
