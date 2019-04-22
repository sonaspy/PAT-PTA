	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.file	1 "demo.c"
	.globl	_swap
	.p2align	4, 0x90
_swap:                                  ## @swap
Lfunc_begin0:
	.loc	1 8 0                   ## demo.c:8:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movq	_buf@GOTPCREL(%rip), %rax
	addq	$4, %rax
Ltmp0:
	.loc	1 10 11 prologue_end    ## demo.c:10:11
	movq	%rax, _bufp1(%rip)
	.loc	1 11 13                 ## demo.c:11:13
	movq	_bufp0(%rip), %rax
	.loc	1 11 12 is_stmt 0       ## demo.c:11:12
	movl	(%rax), %ecx
	.loc	1 11 10                 ## demo.c:11:10
	movl	%ecx, -4(%rbp)
	.loc	1 12 15 is_stmt 1       ## demo.c:12:15
	movq	_bufp1(%rip), %rax
	.loc	1 12 14 is_stmt 0       ## demo.c:12:14
	movl	(%rax), %ecx
	.loc	1 12 6                  ## demo.c:12:6
	movq	_bufp0(%rip), %rax
	.loc	1 12 12                 ## demo.c:12:12
	movl	%ecx, (%rax)
	.loc	1 13 14 is_stmt 1       ## demo.c:13:14
	movl	-4(%rbp), %ecx
	.loc	1 13 6 is_stmt 0        ## demo.c:13:6
	movq	_bufp1(%rip), %rax
	.loc	1 13 12                 ## demo.c:13:12
	movl	%ecx, (%rax)
	.loc	1 14 1 is_stmt 1        ## demo.c:14:1
	popq	%rbp
	retq
Ltmp1:
Lfunc_end0:
	.cfi_endproc

	.section	__DATA,__data
	.globl	_bufp0                  ## @bufp0
	.p2align	3
_bufp0:
	.quad	_buf

.zerofill __DATA,__bss,_bufp1,8,3       ## @bufp1
	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple LLVM version 9.0.0 (clang-900.0.39.2)" ## string offset=0
	.asciz	"demo.c"                ## string offset=44
	.asciz	"/Users/sonAspy/github_rep/PTA/PRIMER" ## string offset=51
	.asciz	"bufp0"                 ## string offset=88
	.asciz	"int"                   ## string offset=94
	.asciz	"bufp1"                 ## string offset=98
	.asciz	"swap"                  ## string offset=104
	.asciz	"temp"                  ## string offset=109
	.section	__DWARF,__debug_loc,regular,debug
Lsection_debug_loc:
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                       ## Abbreviation Code
	.byte	17                      ## DW_TAG_compile_unit
	.byte	1                       ## DW_CHILDREN_yes
	.byte	37                      ## DW_AT_producer
	.byte	14                      ## DW_FORM_strp
	.byte	19                      ## DW_AT_language
	.byte	5                       ## DW_FORM_data2
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	16                      ## DW_AT_stmt_list
	.byte	23                      ## DW_FORM_sec_offset
	.byte	27                      ## DW_AT_comp_dir
	.byte	14                      ## DW_FORM_strp
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	2                       ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	3                       ## Abbreviation Code
	.byte	15                      ## DW_TAG_pointer_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	4                       ## Abbreviation Code
	.byte	36                      ## DW_TAG_base_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	62                      ## DW_AT_encoding
	.byte	11                      ## DW_FORM_data1
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	5                       ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	6                       ## Abbreviation Code
	.byte	46                      ## DW_TAG_subprogram
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	64                      ## DW_AT_frame_base
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	7                       ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	0                       ## EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
	.long	129                     ## Length of Unit
	.short	4                       ## DWARF version number
Lset0 = Lsection_abbrev-Lsection_abbrev ## Offset Into Abbrev. Section
	.long	Lset0
	.byte	8                       ## Address Size (in bytes)
	.byte	1                       ## Abbrev [1] 0xb:0x7a DW_TAG_compile_unit
	.long	0                       ## DW_AT_producer
	.short	12                      ## DW_AT_language
	.long	44                      ## DW_AT_name
Lset1 = Lline_table_start0-Lsection_line ## DW_AT_stmt_list
	.long	Lset1
	.long	51                      ## DW_AT_comp_dir
	.quad	Lfunc_begin0            ## DW_AT_low_pc
Lset2 = Lfunc_end0-Lfunc_begin0         ## DW_AT_high_pc
	.long	Lset2
	.byte	2                       ## Abbrev [2] 0x2a:0x15 DW_TAG_variable
	.long	88                      ## DW_AT_name
	.long	63                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	1                       ## DW_AT_decl_file
	.byte	5                       ## DW_AT_decl_line
	.byte	9                       ## DW_AT_location
	.byte	3
	.quad	_bufp0
	.byte	3                       ## Abbrev [3] 0x3f:0x5 DW_TAG_pointer_type
	.long	68                      ## DW_AT_type
	.byte	4                       ## Abbrev [4] 0x44:0x7 DW_TAG_base_type
	.long	94                      ## DW_AT_name
	.byte	5                       ## DW_AT_encoding
	.byte	4                       ## DW_AT_byte_size
	.byte	5                       ## Abbrev [5] 0x4b:0x15 DW_TAG_variable
	.long	98                      ## DW_AT_name
	.long	63                      ## DW_AT_type
	.byte	1                       ## DW_AT_decl_file
	.byte	6                       ## DW_AT_decl_line
	.byte	9                       ## DW_AT_location
	.byte	3
	.quad	_bufp1
	.byte	6                       ## Abbrev [6] 0x60:0x24 DW_TAG_subprogram
	.quad	Lfunc_begin0            ## DW_AT_low_pc
Lset3 = Lfunc_end0-Lfunc_begin0         ## DW_AT_high_pc
	.long	Lset3
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	104                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	7                       ## DW_AT_decl_line
                                        ## DW_AT_external
	.byte	7                       ## Abbrev [7] 0x75:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	124
	.long	109                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	9                       ## DW_AT_decl_line
	.long	68                      ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.section	__DWARF,__debug_ranges,regular,debug
Ldebug_range:
	.section	__DWARF,__debug_macinfo,regular,debug
Ldebug_macinfo:
Lcu_macro_begin0:
	.byte	0                       ## End Of Macro List Mark
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	3                       ## Header Bucket Count
	.long	3                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	0                       ## Bucket 0
	.long	-1                      ## Bucket 1
	.long	2                       ## Bucket 2
	.long	254691939               ## Hash in Bucket 0
	.long	2090739264              ## Hash in Bucket 0
	.long	254691938               ## Hash in Bucket 2
	.long	LNames2-Lnames_begin    ## Offset in Bucket 0
	.long	LNames0-Lnames_begin    ## Offset in Bucket 0
	.long	LNames1-Lnames_begin    ## Offset in Bucket 2
LNames2:
	.long	98                      ## bufp1
	.long	1                       ## Num DIEs
	.long	75
	.long	0
LNames0:
	.long	104                     ## swap
	.long	1                       ## Num DIEs
	.long	96
	.long	0
LNames1:
	.long	88                      ## bufp0
	.long	1                       ## Num DIEs
	.long	42
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	1                       ## Header Hash Count
	.long	20                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	3                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.short	3                       ## DW_ATOM_die_tag
	.short	5                       ## DW_FORM_data2
	.short	4                       ## DW_ATOM_type_flags
	.short	11                      ## DW_FORM_data1
	.long	0                       ## Bucket 0
	.long	193495088               ## Hash in Bucket 0
	.long	Ltypes0-Ltypes_begin    ## Offset in Bucket 0
Ltypes0:
	.long	94                      ## int
	.long	1                       ## Num DIEs
	.long	68
	.short	36
	.byte	0
	.long	0

.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
