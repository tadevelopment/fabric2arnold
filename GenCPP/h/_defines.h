/**
  This file contains some useful defines that will be applied throughout the project
  */

#pragma once

#define F2A_TRY_STATEMENT(x)
#define F2A_CATCH_STATEMENT(x)
#define F2A_CATCH_STATEMENT_RETURN(x, y) return _result;

// This won't (shouldn't) compile on Windows.  Fix to portable version when your back on a dceent OS/compiler
#ifndef nullptr
#define nullptr NULL
#endif

#define static_assert(x,msg)
