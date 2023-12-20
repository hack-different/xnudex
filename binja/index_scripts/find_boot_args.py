

PE_BOOT_ARGN = bv.get_functions_by_name("PE_parse_boot_argn")[0]
PE_BOOT_ARNG_INTERNAL = bv.get_functions_by_name("PE_parse_boot_argn_internal")[0]

argn_list = []

for call_site in PE_BOOT_ARNG_INTERNAL.caller_sites:
    if not isinstance(call_site.hlil, HighLevelILCall): 
        continue
    argn_param = call_site.hlil.params[1]
    if not isinstance(argn_param, HighLevelILConstPtr):
        continue
    argn_name = argn_param.tokens[1]
    if argn_name not in argn_list:
        argn_list.append(argn_name)

print(argn_list)