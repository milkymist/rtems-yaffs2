/*
 * YAFFS: Yet another FFS. A NAND-flash specific file system.
 *
 * Copyright (C) 2002-2010 Aleph One Ltd.
 *   for Toby Churchill Ltd and Brightstar Engineering
 *
 * Created by Timothy Manning <timothy@yaffs.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "yaffs_error_converter.h"

typedef struct error_codes_template {
  int code;
  char * text;  
}error_entry;

const error_entry error_list[] = {
	{ ENOMEM , "ENOMEM" },
	{ EBUSY , "EBUSY"},
	{ ENODEV , "ENODEV"},
	{ EINVAL , "EINVAL"},
	{ EBADF , "EBADF"},
	{ EACCES , "EACCES"},
	{ EXDEV , "EXDEV" },
	{ ENOENT , "ENOENT"},
	{ ENOSPC , "ENOSPC"},
	{ ERANGE , "ERANGE"},
	{ ENODATA, "ENODATA"},
	{ ENOTEMPTY, "ENOTEMPTY"},
	{ ENAMETOOLONG,"ENAMETOOLONG"},
	{ ENOMEM , "ENOMEM"},
	{ EEXIST , "EEXIST"},
	{ ENOTDIR , "ENOTDIR"},
	{ EISDIR , "EISDIR"},
	{ ENFILE, "ENFILE"},
	{ EROFS, "EROFS"},
	{ 0, NULL }
};

const char * yaffs_error_to_str(int err)
{
	error_entry *e = error_list;
	if (err < 0) 
		err = -err;
	while(e->code && e->text){
		if(err == e->code)
			return e->text;
		e++;
	}
	return "Unknown error code";
}

