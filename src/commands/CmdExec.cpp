////////////////////////////////////////////////////////////////////////////////
// taskwarrior - a command line task list manager.
//
// Copyright 2006 - 2011, Paul Beckingham, Federico Hernandez.
// All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the
//
//     Free Software Foundation, Inc.,
//     51 Franklin Street, Fifth Floor,
//     Boston, MA
//     02110-1301
//     USA
//
////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <Context.h>
#include <CmdExec.h>

extern Context context;

////////////////////////////////////////////////////////////////////////////////
CmdExec::CmdExec ()
{
  _keyword     = "execute";
  _usage       = "task execute <external command>";
  _description = "Executes external commands and scripts";
  _read_only   = false;
  _displays_id = true;
}

////////////////////////////////////////////////////////////////////////////////
int CmdExec::execute (std::string& output)
{
  std::string command_line;
  std::vector <std::pair <std::string, std::string> >::iterator arg;
  for (arg = context.args.begin (); arg != context.args.end (); ++arg)
  {
    if (arg != context.args.begin () &&
        arg->first != "execute")
      command_line += arg->first;
  }

  return system (command_line.c_str ());
}

////////////////////////////////////////////////////////////////////////////////
