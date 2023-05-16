statetype s_taterwalk1 = {TATERTROOPWALKL1SPR,TATERTROOPWALKR1SPR,step,false, true,10, 128,0, TaterThink, NULL, WalkReact, &s_taterwalk2};
statetype s_taterwalk2 = {TATERTROOPWALKL2SPR,TATERTROOPWALKR2SPR,step,false, true,10, 128,0, TaterThink, NULL, WalkReact, &s_taterwalk3};
statetype s_taterwalk3 = {TATERTROOPWALKL3SPR,TATERTROOPWALKR3SPR,step,false, true,10, 128,0, TaterThink, NULL, WalkReact, &s_taterwalk4};
statetype s_taterwalk4 = {TATERTROOPWALKL4SPR,TATERTROOPWALKR4SPR,step,false, true,10, 128,0, TaterThink, NULL, WalkReact, &s_taterwalk1};

statetype s_taterattack1 = {TATERTROOPLUNGEL1SPR,TATERTROOPLUNGER1SPR,step,false, false,12, 0,0, NULL, NULL, BackupReact, &s_taterattack2};
statetype s_taterattack2 = {TATERTROOPLUNGEL2SPR,TATERTROOPLUNGER2SPR,step,false, false,20, 0,0, NULL, NULL, DrawReact, &s_taterattack3};
statetype s_taterattack3 = {TATERTROOPLUNGEL1SPR,TATERTROOPLUNGER1SPR,step,false, false,8, 0,0, NULL, NULL, DrawReact, &s_taterwalk1};
