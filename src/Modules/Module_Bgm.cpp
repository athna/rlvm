// -*- Mode: C++; tab-width:2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi:tw=80:et:ts=2:sts=2
//
// -----------------------------------------------------------------------
//
// This file is part of RLVM, a RealLive virtual machine clone.
//
// -----------------------------------------------------------------------
//
// Copyright (C) 2007 Elliot Glaysher
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// -----------------------------------------------------------------------

#include "Precompiled.hpp"

// -----------------------------------------------------------------------

#include "Modules/Module_Bgm.hpp"

#include "MachineBase/RLMachine.hpp"
#include "MachineBase/RLOperation.hpp"
#include "MachineBase/GeneralOperations.hpp"
#include "MachineBase/RLOperation/RLOp_Store.hpp"
#include "Systems/Base/System.hpp"
#include "Systems/Base/SoundSystem.hpp"

// -----------------------------------------------------------------------

struct Bgm_bgmLoop_0 : public RLOp_Void_1<StrConstant_T> {
  void operator()(RLMachine& machine, string filename) {
    machine.system().sound().bgmPlay(filename, true);
  }
};

// -----------------------------------------------------------------------

struct Bgm_bgmLoop_1 : public RLOp_Void_2<StrConstant_T, IntConstant_T> {
  void operator()(RLMachine& machine, string filename, int fadein) {
    machine.system().sound().bgmPlay(filename, true, fadein);
  }
};

// -----------------------------------------------------------------------

struct Bgm_bgmLoop_2 : public RLOp_Void_3<StrConstant_T, IntConstant_T,
                                          IntConstant_T> {
  void operator()(RLMachine& machine, string filename, int fadein,
                  int fadeout) {
    machine.system().sound().bgmPlay(filename, true, fadein, fadeout);
  }
};

// -----------------------------------------------------------------------

struct Bgm_bgmPlay_0 : public RLOp_Void_1<StrConstant_T> {
  void operator()(RLMachine& machine, string filename) {
    machine.system().sound().bgmPlay(filename, false);
  }
};

// -----------------------------------------------------------------------

struct Bgm_bgmPlay_1 : public RLOp_Void_2<StrConstant_T, IntConstant_T> {
  void operator()(RLMachine& machine, string filename, int fadein) {
    machine.system().sound().bgmPlay(filename, false, fadein);
  }
};

// -----------------------------------------------------------------------

struct Bgm_bgmPlay_2 : public RLOp_Void_3<StrConstant_T, IntConstant_T,
                                          IntConstant_T> {
  void operator()(RLMachine& machine, string filename, int fadein,
                  int fadeout) {
    machine.system().sound().bgmPlay(filename, false, fadein, fadeout);
  }
};

// -----------------------------------------------------------------------

struct Bgm_bgmPlaying : public RLOp_Store_Void {
  int operator()(RLMachine& machine) {
    return machine.system().sound().bgmStatus() == 1;
  }
};

// -----------------------------------------------------------------------

struct Bgm_bgmFadeOut : public RLOp_Void_1<IntConstant_T> {
  void operator()(RLMachine& machine, int fadetime) {
    machine.system().sound().bgmFadeOut(fadetime);
  }
};

// -----------------------------------------------------------------------

BgmModule::BgmModule()
  : RLModule("Bgm", 1, 20)
{
  // fun \\([A-Za-z0-9]+\\) +<1:Bgm:\\([0-9]+\\), \\([0-9]+\\).*$
  addOpcode(0, 0, "bgmLoop", new Bgm_bgmLoop_0);
  addOpcode(0, 1, "bgmLoop", new Bgm_bgmLoop_1);
  addOpcode(0, 2, "bgmLoop", new Bgm_bgmLoop_2);

  addUnsupportedOpcode(1, 0, "bgmPlayEx");
  addUnsupportedOpcode(1, 1, "bgmPlayEx");
  addUnsupportedOpcode(1, 2, "bgmPlayEx");

  addOpcode(2, 0, "bgmPlay", new Bgm_bgmPlay_0);
  addOpcode(2, 1, "bgmPlay", new Bgm_bgmPlay_1);
  addOpcode(2, 2, "bgmPlay", new Bgm_bgmPlay_2);

  addUnsupportedOpcode(3, 0, "bgmWait");
  addOpcode(4, 0, "bgmPlaying", new Bgm_bgmPlaying);
  addOpcode(5, 0, "bgmStop", callFunction(&SoundSystem::bgmStop));
  addOpcode(6, 0, "bgmStop2", callFunction(&SoundSystem::bgmStop));
  addUnsupportedOpcode(6, 0, "bgmStop2");
  addOpcode(7, 0, "bgmStatus", returnIntValue(&SoundSystem::bgmStatus));
  addUnsupportedOpcode(8, 0, "bgmRewind");
  addOpcode(9, 0, "bgmPause", callFunction(&SoundSystem::bgmPause));
  addOpcode(10, 0, "bgmUnPause", callFunction(&SoundSystem::bgmUnPause));
  addUnsupportedOpcode(11, 0, "bgmVolume");

  addUnsupportedOpcode(12, 0, "bgmSetVolume");
  addUnsupportedOpcode(12, 1, "bgmSetVolume");
  addUnsupportedOpcode(13, 0, "bgmUnMute");
  addUnsupportedOpcode(13, 1, "bgmUnMute");
  addUnsupportedOpcode(14, 0, "bgmMute");
  addUnsupportedOpcode(14, 1, "bgmMute");

  addOpcode(105, 0, "bgmFadeOut", new Bgm_bgmFadeOut);

  addUnsupportedOpcode(106, 0, "bgmFadeOutEx");
  addUnsupportedOpcode(106, 1, "bgmFadeOutEx");

  addUnsupportedOpcode(107, 0, "bgmStatus2");
  addUnsupportedOpcode(200, 0, "bgmTimer");
}
