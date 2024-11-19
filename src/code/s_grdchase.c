statetype s_peapodwalk1	= {PEAPODRUNL1SPR,PEAPODRUNR1SPR,step,false, true,10, 128,0, PeaPodThink, NULL, WalkReact, &s_peapodwalk2};
statetype s_peapodwalk2	= {PEAPODRUNL2SPR,PEAPODRUNR2SPR,step,false, true,10, 128,0, PeaPodThink, NULL, WalkReact, &s_peapodwalk3};
statetype s_peapodwalk3	= {PEAPODRUNL3SPR,PEAPODRUNR3SPR,step,false, true,10, 128,0, PeaPodThink, NULL, WalkReact, &s_peapodwalk4};
statetype s_peapodwalk4	= {PEAPODRUNL4SPR,PEAPODRUNR4SPR,step,false, true,10, 128,0, PeaPodThink, NULL, WalkReact, &s_peapodwalk1};

statetype s_peapodspit1	= {PEAPODSPITLSPR,PEAPODSPITRSPR,step,false, true,30, 0,0, SpitPeaBrain, NULL, DrawReact, &s_peapodspit2};
statetype s_peapodspit2	= {PEAPODSPITLSPR,PEAPODSPITRSPR,step,false, true,30, 0,0, NULL, NULL, DrawReact, &s_peapodwalk1};
