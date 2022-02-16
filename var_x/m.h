#pragma once

enum mathstream {
	madd,
	msub,
	mmul,
	mdiv,
	mmod,
	mpow,
	mlog,
	mroot
};

void math_function();
void math_graph();
void math_cal();
void math_set();

void math_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+fun"):
			case COREFC("+function")://solves for one values
				math_function();
				break;
			case COREFC("+graph")://solves for multiple values
				math_graph();
				break;
			case COREFC("+cal"):
			case COREFC("+calculate")://preforms one mathematical function
				math_cal();
				break;
			case COREFC("+set"):
				math_set();
				break;
			//standard:
       		case COREFC("m*")://sexit
        	case COREFC("~~~*")://uexit
          		return;
        	case COREFC("%")://abstract register
          		abstract_register();
          		break;
        	case COREFC("@*")://assignment wrap
          	assignment_wrap();
          		break;
        	case COREFC("**")://debug point
          		debug_point();
          		break;
        	case COREFC("")://whitespace
          		break;
        	case COREFC("*~~~")://channelswap stream
          		channelswap_stream();
          		break;
      		default:
        		error_stream();
        		break;
        }
	} loop;
}

void math_function() {
	uint16_t math_var_type = actiontype::action_int64;
	uint32_t math_var_name;
	string math_parcer_string = "";
	fc_getline();
	fc_getline();
	long double functionselfref [1];
	switch(active_script[line-1]) {
		case COREFC("_int64"):
			math_var_type = actiontype::action_int64;
			functionselfref[0] = static_cast<long double>(codex_return_int64(active_script[line]));
			break;
		case COREFC("_int32"):
			math_var_type = actiontype::action_int32;
			functionselfref[0] = static_cast<long double>(codex_return_int32(active_script[line]));
			break;
		case COREFC("_int16"):
			math_var_type = actiontype::action_int16;
			functionselfref[0] = static_cast<long double>(codex_return_int16(active_script[line]));
			break;
		case COREFC("_int8"):
			math_var_type = actiontype::action_int8;
			functionselfref[0] = static_cast<long double>(codex_return_int8(active_script[line]));
			break;
		case COREFC("_bool"):
			math_var_type = actiontype::action_bool;
			functionselfref[0] = static_cast<long double>(codex_return_bool(active_script[line]));
			break;
		case COREFC("_triple"):
			math_var_type = actiontype::action_triple;
			functionselfref[0] = codex_return_triple(active_script[line]);
			break;
		case COREFC("_double"):
			math_var_type = actiontype::action_double;
			functionselfref[0] = static_cast<long double>(codex_return_double(active_script[line]));
			break;
		case COREFC("_float"):
			math_var_type = actiontype::action_float;
			functionselfref[0] = static_cast<long double>(codex_return_float(active_script[line]));
			break;
		case COREFC("_string"):
			math_var_type = actiontype::action_string;
			functionselfref[0] = atof(codex_return_string(active_script[line]).c_str());
			break;
		default:
		error_stream();
			break;
	}
	math_var_name = active_script[line];
	bool mathfunctionloop = true;
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_ret"):
				mathfunctionloop = false;
				break;
			default:
				math_parcer_string += codex_get_string(active_script[line]);
				break;
		}
		
		} while(mathfunctionloop==true);

}
void math_graph() {

}
void math_cal() {
	uint16_t math_var_type = actiontype::action_int64;
	uint32_t math_output_var;
	uint16_t math_operator;
	fc_getline();
	switch(active_script[line]) {
		case COREFC("_int64"):
			math_var_type = actiontype::action_int64;
			break;
		case COREFC("_int32"):
			math_var_type = actiontype::action_int32;
			break;
		case COREFC("_int16"):
			math_var_type = actiontype::action_int16;
			break;
		case COREFC("_int8"):
			math_var_type = actiontype::action_int8;
			break;
		case COREFC("_bool"):
			math_var_type = actiontype::action_bool;
			break;
		case COREFC("_triple"):
			math_var_type = actiontype::action_triple;
			break;
		case COREFC("_double"):
			math_var_type = actiontype::action_double;
			break;
		case COREFC("_float"):
			math_var_type = actiontype::action_float;
			break;
		case COREFC("_string"):
			math_var_type = actiontype::action_string;
			break;
		default:
		error_stream();
			break;
	}
	fc_getline();
	math_output_var = active_script[line];
	fc_getline();
	switch(active_script[line]) {
		case COREFC("+")://addition
		case COREFC("_add"):
			math_operator = mathstream::madd;
			break;
		case COREFC("-")://subtraction
		case COREFC("_sub"):
			math_operator = mathstream::msub;
			break;
		case COREFC("*")://multiplication
		case COREFC("_mul"):
			math_operator = mathstream::mmul;
			break;
		case COREFC("/")://division
		case COREFC("_div"):
			math_operator = mathstream::mdiv;
			break;
		case COREFC("%")://modulose
		case COREFC("_mod"):
			math_operator = mathstream::mmod;
			break;
		case COREFC("^")://power
		case COREFC("_pow"):
			math_operator = mathstream::mpow;
			break;
		case COREFC("log")://log
		case COREFC("_log"):
			math_operator = mathstream::mlog;
			break;
		case COREFC("root")://root
		case COREFC("_root"):
			math_operator = mathstream::mroot;
			break;
		default:
			error_stream();
			break;
	}
	fc_getline();

}
void math_set() {

}