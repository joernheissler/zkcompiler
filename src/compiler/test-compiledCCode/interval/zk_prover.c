/* begin c-source-code of program "prover" */
#include "zk_prover.h"

/* mini */
static mpz_t g_mpzVar1;
/* maxi */
static mpz_t g_mpzVar2;
/* minitight */
static mpz_t g_mpzVar3;
/* maxitight */
static mpz_t g_mpzVar4;
/* n */
static mpz_t g_mpzVar5;
/* mini */
static mpz_t g_mpzVar6;
/* maxi */
static mpz_t g_mpzVar7;
/* minitight */
static mpz_t g_mpzVar8;
/* maxitight */
static mpz_t g_mpzVar9;
/* bnz_t */
static mpz_t g_mpzVar10;
/* bnz_t */
static mpz_t g_mpzVar11;
/* bnz_t */
static mpz_t g_mpzVar12;
/* bnz_t */
static mpz_t g_mpzVar13;
/* bnz_t */
static mpz_t g_mpzVar14;
/* bnz_t */
static mpz_t g_mpzVar15;
/* bnz_t */
static mpz_t g_mpzVar16;
/* bnz_t */
static mpz_t g_mpzVar17;
/* bnz_t */
static mpz_t g_mpzVar18;
/* bnz_t */
static mpz_t g_mpzVar19;
/* bnz_t */
static mpz_t g_mpzVar20;
/* bnz_t */
static mpz_t g_mpzVar21;
/* bnz_t */
static mpz_t g_mpzVar22;
/* bnz_t */
static mpz_t g_mpzVar23;
/* bnz_t */
static mpz_t g_mpzVar24;
/* bnz_t */
static mpz_t g_mpzVar25;
/* bnz_t */
static mpz_t g_mpzVar26;
/* bnz_t */
static mpz_t g_mpzVar27;
/* bnz_t */
static mpz_t g_mpzVar28;
/* bnz_t */
static mpz_t g_mpzVar29;
/* bnz_t */
static mpz_t g_mpzVar30;
/* bnz_t */
static mpz_t g_mpzVar31;
/* bnz_t */
static mpz_t g_mpzVar32;
/* bnz_t */
static mpz_t g_mpzVar33;
/* bnz_t */
static mpz_t g_mpzVar34;
/* bnz_t */
static mpz_t g_mpzVar35;
/* bnz_t */
static mpz_t g_mpzVar36;
/* bnz_t */
static mpz_t g_mpzVar37;
/* bnz_t */
static mpz_t g_mpzVar38;
/* bnz_t */
static mpz_t g_mpzVar39;
/* bnz_t */
static mpz_t g_mpzVar40;
/* bnz_t */
static mpz_t g_mpzVar41;
/* bnz_t */
static mpz_t g_mpzVar42;
/* bnz_t */
static mpz_t g_mpzVar43;
/* bnz_t */
static mpz_t g_mpzVar44;
/* bnz_t */
static mpz_t g_mpzVar45;
/* bnz_t */
static mpz_t g_mpzVar46;
/* bnz_t */
static mpz_t g_mpzVar47;
/* bnz_t */
static mpz_t g_mpzVar48;
/* bnz_t */
static mpz_t g_mpzVar49;
/* bnz_t */
static mpz_t g_mpzVar50;
/* bnz_t */
static mpz_t g_mpzVar51;
/* bnz_t */
static mpz_t g_mpzVar52;
/* bnz_t */
static mpz_t g_mpzVar53;
/* bnz_t */
static mpz_t g_mpzVar54;
/* bnz_t */
static mpz_t g_mpzVar55;
/* bnz_t */
static mpz_t g_mpzVar56;
/* bnz_t */
static mpz_t g_mpzVar57;
/* bnz_t */
static mpz_t g_mpzVar58;
/* bnz_t */
static mpz_t g_mpzVar59;
/* bnz_t */
static mpz_t g_mpzVar60;
/* bnz_t */
static mpz_t g_mpzVar61;
/* bnz_t */
static mpz_t g_mpzVar62;
/* bnz_t */
static mpz_t g_mpzVar63;
/* bnz_t */
static mpz_t g_mpzVar64;
/* bnz_t */
static mpz_t g_mpzVar65;
/* bnz_t */
static mpz_t g_mpzVar66;
/* bnz_t */
static mpz_t g_mpzVar67;
/* bnz_t */
static mpz_t g_mpzVar68;
/* bnz_t */
static mpz_t g_mpzVar69;
/* bnz_t */
static mpz_t g_mpzVar70;
/* bnz_t */
static mpz_t g_mpzVar71;
/* bnz_t */
static mpz_t g_mpzVar72;
/* bnz_t */
static mpz_t g_mpzVar73;
/* bnz_t */
static mpz_t g_mpzVar74;
/* bnz_t */
static mpz_t g_mpzVar75;
/* bnz_t */
static mpz_t g_mpzVar76;
/* bnz_t */
static mpz_t g_mpzVar77;
/* bnz_t */
static mpz_t g_mpzVar78;
/* bnz_t */
static mpz_t g_mpzVar79;
/* bnz_t */
static mpz_t g_mpzVar80;
/* bnz_t */
static mpz_t g_mpzVar81;
/* bnz_t */
static mpz_t g_mpzVar82;
/* bnz_t */
static mpz_t g_mpzVar83;
/* bnz_t */
static mpz_t g_mpzVar84;
/* bnz_t */
static mpz_t g_mpzVar85;
/* bnz_t */
static mpz_t g_mpzVar86;
/* bnz_t */
static mpz_t g_mpzVar87;
/* bnz_t */
static mpz_t g_mpzVar88;
/* bnz_t */
static mpz_t g_mpzVar89;
/* bnz_t */
static mpz_t g_mpzVar90;
/* bnz_t */
static mpz_t g_mpzVar91;
/* bnz_t */
static mpz_t g_mpzVar92;
/* bnz_t */
static mpz_t g_mpzVar93;
/* bnz_t */
static mpz_t g_mpzVar94;
/* bnz_t */
static mpz_t g_mpzVar95;
/* bnz_t */
static mpz_t g_mpzVar96;
/* bnz_t */
static mpz_t g_mpzVar97;
/* bnz_t */
static mpz_t g_mpzVar98;
/* bnz_t */
static mpz_t g_mpzVar99;
/* bnz_t */
static mpz_t g_mpzVar100;
/* bnz_t */
static mpz_t g_mpzVar101;
/* bnz_t */
static mpz_t g_mpzVar102;
/* bnz_t */
static mpz_t g_mpzVar103;
/* bnz_t */
static mpz_t g_mpzVar104;
/* bnz_t */
static mpz_t g_mpzVar105;
/* bnz_t */
static mpz_t g_mpzVar106;
/* bnz_t */
static mpz_t g_mpzVar107;
/* bnz_t */
static mpz_t g_mpzVar108;
/* bnz_t */
static mpz_t g_mpzVar109;
/* bnz_t */
static mpz_t g_mpzVar110;
/* bnz_t */
static mpz_t g_mpzVar111;
/* bnz_t */
static mpz_t g_mpzVar112;
/* bnz_t */
static mpz_t g_mpzVar113;
/* bnz_t */
static mpz_t g_mpzVar114;
/* bnz_t */
static mpz_t g_mpzVar115;
/* bnz_t */
static mpz_t g_mpzVar116;
/* bnz_t */
static mpz_t g_mpzVar117;
/* bnz_t */
static mpz_t g_mpzVar118;
/* bnz_t */
static mpz_t g_mpzVar119;
/* bnz_t */
static mpz_t g_mpzVar120;
/* bnz_t */
static mpz_t g_mpzVar121;
/* bnz_t */
static mpz_t g_mpzVar122;
/* bnz_t */
static mpz_t g_mpzVar123;
/* bnz_t */
static mpz_t g_mpzVar124;
/* bnz_t */
static mpz_t g_mpzVar125;
/* bnz_t */
static mpz_t g_mpzVar126;
/* bnz_t */
static mpz_t g_mpzVar127;
/* bnz_t */
static mpz_t g_mpzVar128;
/* bnz_t */
static mpz_t g_mpzVar129;
/* bnz_t */
static mpz_t g_mpzVar130;
/* bnz_t */
static mpz_t g_mpzVar131;
/* bnz_t */
static mpz_t g_mpzVar132;
/* bnz_t */
static mpz_t g_mpzVar133;
/* bnz_t */
static mpz_t g_mpzVar134;
/* bnz_t */
static mpz_t g_mpzVar135;
/* bnz_t */
static mpz_t g_mpzVar136;
/* bnz_t */
static mpz_t g_mpzVar137;
/* bnz_t */
static mpz_t g_mpzVar138;
/* bnz_t */
static mpz_t g_mpzVar139;
/* bnz_t */
static mpz_t g_mpzVar140;
/* bnz_t */
static mpz_t g_mpzVar141;
/* bnz_t */
static mpz_t g_mpzVar142;
/* bnz_t */
static mpz_t g_mpzVar143;
/* bnz_t */
static mpz_t g_mpzVar144;
/* bnz_t */
static mpz_t g_mpzVar145;
/* bnz_t */
static mpz_t g_mpzVar146;
/* bnz_t */
static mpz_t g_mpzVar147;
/* bnz_t */
static mpz_t g_mpzVar148;
/* bnz_t */
static mpz_t g_mpzVar149;
/* bnz_t */
static mpz_t g_mpzVar150;
/* bnz_t */
static mpz_t g_mpzVar151;
/* bnz_t */
static mpz_t g_mpzVar152;
/* bnz_t */
static mpz_t g_mpzVar153;
/* bnz_t */
static mpz_t g_mpzVar154;
/* bnz_t */
static mpz_t g_mpzVar155;
/* bnz_t */
static mpz_t g_mpzVar156;
/* bnz_t */
static mpz_t g_mpzVar157;
/* bnz_t */
static mpz_t g_mpzVar158;
/* bnz_t */
static mpz_t g_mpzVar159;
/* bnz_t */
static mpz_t g_mpzVar160;
/* bnz_t */
static mpz_t g_mpzVar161;
/* bnz_t */
static mpz_t g_mpzVar162;
/* bnz_t */
static mpz_t g_mpzVar163;
/* bnz_t */
static mpz_t g_mpzVar164;
/* bnz_t */
static mpz_t g_mpzVar165;
/* bnz_t */
static mpz_t g_mpzVar166;
/* bnz_t */
static mpz_t g_mpzVar167;
/* bnz_t */
static mpz_t g_mpzVar168;
/* bnz_t */
static mpz_t g_mpzVar169;
/* bnz_t */
static mpz_t g_mpzVar170;
/* bnz_t */
static mpz_t g_mpzVar171;
/* bnz_t */
static mpz_t g_mpzVar172;
/* bnz_t */
static mpz_t g_mpzVar173;
/* bnz_t */
static mpz_t g_mpzVar174;
/* bnz_t */
static mpz_t g_mpzVar175;
/* bnz_t */
static mpz_t g_mpzVar176;
/* bnz_t */
static mpz_t g_mpzVar177;
/* bnz_t */
static mpz_t g_mpzVar178;
/* bnz_t */
static mpz_t g_mpzVar179;
/* bnz_t */
static mpz_t g_mpzVar180;
/* bnz_t */
static mpz_t g_mpzVar181;
/* bnz_t */
static mpz_t g_mpzVar182;
/* bnz_t */
static mpz_t g_mpzVar183;
/* bnz_t */
static mpz_t g_mpzVar184;
/* bnz_t */
static mpz_t g_mpzVar185;
/* bnz_t */
static mpz_t g_mpzVar186;
/* bnz_t */
static mpz_t g_mpzVar187;
/* bnz_t */
static mpz_t g_mpzVar188;
/* bnz_t */
static mpz_t g_mpzVar189;
/* bnz_t */
static mpz_t g_mpzVar190;
/* bnz_t */
static mpz_t g_mpzVar191;
/* bnz_t */
static mpz_t g_mpzVar192;
/* bnz_t */
static mpz_t g_mpzVar193;
/* bnz_t */
static mpz_t g_mpzVar194;
/* bnz_t */
static mpz_t g_mpzVar195;
/* bnz_t */
static mpz_t g_mpzVar196;
/* bnz_t */
static mpz_t g_mpzVar197;
/* bnz_t */
static mpz_t g_mpzVar198;
/* bnz_t */
static mpz_t g_mpzVar199;
/* bnz_t */
static mpz_t g_mpzVar200;
/* bnz_t */
static mpz_t g_mpzVar201;
/* bnz_t */
static mpz_t g_mpzVar202;
/* bnz_t */
static mpz_t g_mpzVar203;
/* bnz_t */
static mpz_t g_mpzVar204;
/* bnz_t */
static mpz_t g_mpzVar205;
/* bnz_t */
static mpz_t g_mpzVar206;
/* bnz_t */
static mpz_t g_mpzVar207;
/* bnz_t */
static mpz_t g_mpzVar208;
/* bnz_t */
static mpz_t g_mpzVar209;
/* bnz_t */
static mpz_t g_mpzVar210;
/* bnz_t */
static mpz_t g_mpzVar211;
/* bnz_t */
static mpz_t g_mpzVar212;
/* bnz_t */
static mpz_t g_mpzVar213;
/* bnz_t */
static mpz_t g_mpzVar214;
/* bnz_t */
static mpz_t g_mpzVar215;
/* bnz_t */
static mpz_t g_mpzVar216;
/* bnz_t */
static mpz_t g_mpzVar217;
/* bnz_t */
static mpz_t g_mpzVar218;
/* bnz_t */
static mpz_t g_mpzVar219;
/* bnz_t */
static mpz_t g_mpzVar220;
/* bnz_t */
static mpz_t g_mpzVar221;
/* bnz_t */
static mpz_t g_mpzVar222;
/* bnz_t */
static mpz_t g_mpzVar223;
/* bnz_t */
static mpz_t g_mpzVar224;
/* bnz_t */
static mpz_t g_mpzVar225;
/* bnz_t */
static mpz_t g_mpzVar226;
/* bnz_t */
static mpz_t g_mpzVar227;
/* bnz_t */
static mpz_t g_mpzVar228;
/* bnz_t */
static mpz_t g_mpzVar229;
/* bnz_t */
static mpz_t g_mpzVar230;
/* bnz_t */
static mpz_t g_mpzVar231;
/* bnz_t */
static mpz_t g_mpzVar232;
/* bnz_t */
static mpz_t g_mpzVar233;
/* bnz_t */
static mpz_t g_mpzVar234;
/* bnz_t */
static mpz_t g_mpzVar235;
/* bnz_t */
static mpz_t g_mpzVar236;
/* bnz_t */
static mpz_t g_mpzVar237;
/* bnz_t */
static mpz_t g_mpzVar238;
/* bnz_t */
static mpz_t g_mpzVar239;
/* bnz_t */
static mpz_t g_mpzVar240;
/* bnz_t */
static mpz_t g_mpzVar241;
/* bnz_t */
static mpz_t g_mpzVar242;
/* bnz_t */
static mpz_t g_mpzVar243;
/* bnz_t */
static mpz_t g_mpzVar244;
/* bnz_t */
static mpz_t g_mpzVar245;
/* bnz_t */
static mpz_t g_mpzVar246;
/* bnz_t */
static mpz_t g_mpzVar247;
/* bnz_t */
static mpz_t g_mpzVar248;
/* bnz_t */
static mpz_t g_mpzVar249;
/* bnz_t */
static mpz_t g_mpzVar250;
/* bnz_t */
static mpz_t g_mpzVar251;
/* bnz_t */
static mpz_t g_mpzVar252;
/* bnz_t */
static mpz_t g_mpzVar253;
/* bnz_t */
static mpz_t g_mpzVar254;
/* bnz_t */
static mpz_t g_mpzVar255;
/* bnz_t */
static mpz_t g_mpzVar256;
/* bnz_t */
static mpz_t g_mpzVar257;
/* bnz_t */
static mpz_t g_mpzVar258;
/* bnz_t */
static mpz_t g_mpzVar259;
/* bnz_t */
static mpz_t g_mpzVar260;
/* bnz_t */
static mpz_t g_mpzVar261;
/* bnz_t */
static mpz_t g_mpzVar262;
/* bnz_t */
static mpz_t g_mpzVar263;
/* bnz_t */
static mpz_t g_mpzVar264;
/* bnz_t */
static mpz_t g_mpzVar265;
/* bnz_t */
static mpz_t g_mpzVar266;
/* bnz_t */
static mpz_t g_mpzVar267;
/* bnz_t */
static mpz_t g_mpzVar268;
/* bnz_t */
static mpz_t g_mpzVar269;
/* bnz_t */
static mpz_t g_mpzVar270;
/* bnz_t */
static mpz_t g_mpzVar271;
/* bnz_t */
static mpz_t g_mpzVar272;
/* bnz_t */
static mpz_t g_mpzVar273;
/* bnz_t */
static mpz_t g_mpzVar274;
/* bnz_t */
static mpz_t g_mpzVar275;
/* bnz_t */
static mpz_t g_mpzVar276;
/* bnz_t */
static mpz_t g_mpzVar277;
/* bnz_t */
static mpz_t g_mpzVar278;
/* bnz_t */
static mpz_t g_mpzVar279;
/* bnz_t */
static mpz_t g_mpzVar280;
/* bnz_t */
static mpz_t g_mpzVar281;
/* bnz_t */
static mpz_t g_mpzVar282;
/* bnz_t */
static mpz_t g_mpzVar283;
/* bnz_t */
static mpz_t g_mpzVar284;
/* bnz_t */
static mpz_t g_mpzVar285;
/* bnz_t */
static mpz_t g_mpzVar286;
/* bnz_t */
static mpz_t g_mpzVar287;
/* bnz_t */
static mpz_t g_mpzVar288;
/* bnz_t */
static mpz_t g_mpzVar289;
/* bnz_t */
static mpz_t g_mpzVar290;
/* bnz_t */
static mpz_t g_mpzVar291;
/* bnz_t */
static mpz_t g_mpzVar292;
/* bnz_t */
static mpz_t g_mpzVar293;
/* bnz_t */
static mpz_t g_mpzVar294;
/* bnz_t */
static mpz_t g_mpzVar295;
/* bnz_t */
static mpz_t g_mpzVar296;
/* bnz_t */
static mpz_t g_mpzVar297;
/* bnz_t */
static mpz_t g_mpzVar298;
/* bnz_t */
static mpz_t g_mpzVar299;
/* bnz_t */
static mpz_t g_mpzVar300;
/* bnz_t */
static mpz_t g_mpzVar301;
/* bnz_t */
static mpz_t g_mpzVar302;
/* bnz_t */
static mpz_t g_mpzVar303;
/* bnz_t */
static mpz_t g_mpzVar304;
/* bnz_t */
static mpz_t g_mpzVar305;
/* bnz_t */
static mpz_t g_mpzVar306;
/* bnz_t */
static mpz_t g_mpzVar307;
/* bnz_t */
static mpz_t g_mpzVar308;
/* bnz_t */
static mpz_t g_mpzVar309;
/* bnz_t */
static mpz_t g_mpzVar310;
/* bnz_t */
static mpz_t g_mpzVar311;
/* bnz_t */
static mpz_t g_mpzVar312;
/* bnz_t */
static mpz_t g_mpzVar313;
/* bnz_t */
static mpz_t g_mpzVar314;
/* bnz_t */
static mpz_t g_mpzVar315;
/* bnz_t */
static mpz_t g_mpzVar316;
/* bnz_t */
static mpz_t g_mpzVar317;
/* bnz_t */
static mpz_t g_mpzVar318;
/* bnz_t */
static mpz_t g_mpzVar319;
/* bnz_t */
static mpz_t g_mpzVar320;
/* bnz_t */
static mpz_t g_mpzVar321;
/* bnz_t */
static mpz_t g_mpzVar322;
/* bnz_t */
static mpz_t g_mpzVar323;
/* bnz_t */
static mpz_t g_mpzVar324;
/* bnz_t */
static mpz_t g_mpzVar325;
/* bnz_t */
static mpz_t g_mpzVar326;
/* bnz_t */
static mpz_t g_mpzVar327;
/* bnz_t */
static mpz_t g_mpzVar328;
/* bnz_t */
static mpz_t g_mpzVar329;
/* bnz_t */
static mpz_t g_mpzVar330;
/* bnz_t */
static mpz_t g_mpzVar331;
/* bnz_t */
static mpz_t g_mpzVar332;
/* bnz_t */
static mpz_t g_mpzVar333;
/* bnz_t */
static mpz_t g_mpzVar334;
/* bnz_t */
static mpz_t g_mpzVar335;
/* bnz_t */
static mpz_t g_mpzVar336;
/* bnz_t */
static mpz_t g_mpzVar337;
/* bnz_t */
static mpz_t g_mpzVar338;
/* bnz_t */
static mpz_t g_mpzVar339;
/* bnz_t */
static mpz_t g_mpzVar340;
/* bnz_t */
static mpz_t g_mpzVar341;
/* bnz_t */
static mpz_t g_mpzVar342;
/* bnz_t */
static mpz_t g_mpzVar343;
/* bnz_t */
static mpz_t g_mpzVar344;
/* bnz_t */
static mpz_t g_mpzVar345;
/* bnz_t */
static mpz_t g_mpzVar346;
/* bnz_t */
static mpz_t g_mpzVar347;
/* bnz_t */
static mpz_t g_mpzVar348;
/* bnz_t */
static mpz_t g_mpzVar349;
/* bnz_t */
static mpz_t g_mpzVar350;
/* bnz_t */
static mpz_t g_mpzVar351;
/* bnz_t */
static mpz_t g_mpzVar352;
/* bnz_t */
static mpz_t g_mpzVar353;
/* bnz_t */
static mpz_t g_mpzVar354;
/* bnz_t */
static mpz_t g_mpzVar355;
/* bnz_t */
static mpz_t g_mpzVar356;
/* bnz_t */
static mpz_t g_mpzVar357;
/* bnz_t */
static mpz_t g_mpzVar358;
/* bnz_t */
static mpz_t g_mpzVar359;
/* bnz_t */
static mpz_t g_mpzVar360;
/* bnz_t */
static mpz_t g_mpzVar361;
/* bnz_t */
static mpz_t g_mpzVar362;
/* bnz_t */
static mpz_t g_mpzVar363;
/* bnz_t */
static mpz_t g_mpzVar364;
/* bnz_t */
static mpz_t g_mpzVar365;
/* bnz_t */
static mpz_t g_mpzVar366;
/* bnz_t */
static mpz_t g_mpzVar367;
/* bnz_t */
static mpz_t g_mpzVar368;
/* bnz_t */
static mpz_t g_mpzVar369;
/* bnz_t */
static mpz_t g_mpzVar370;
/* bnz_t */
static mpz_t g_mpzVar371;
/* bnz_t */
static mpz_t g_mpzVar372;
/* bnz_t */
static mpz_t g_mpzVar373;
/* bnz_t */
static mpz_t g_mpzVar374;
/* bnz_t */
static mpz_t g_mpzVar375;
/* bnz_t */
static mpz_t g_mpzVar376;
/* bnz_t */
static mpz_t g_mpzVar377;
/* bnz_t */
static mpz_t g_mpzVar378;
/* bnz_t */
static mpz_t g_mpzVar379;
/* cplus */
static mpz_t g_mpzVar380;
/* c */
static mpz_t g_mpzVar381;
/* l */
static zk_uint g_uiVar382;
/* bnz_t */
static mpz_t g_mpzVar383;
/* bnz_t */
static mpz_t g_mpzVar384;
/* bnz_t */
static mpz_t g_mpzVar385;
/* bnz_t */
static mpz_t g_mpzVar386;
/* bnz_t */
static mpz_t g_mpzVar387;
/* bnz_t */
static mpz_t g_mpzVar388;
/* bnz_t */
static mpz_t g_mpzVar389;
/* bnz_t */
static mpz_t g_mpzVar390;
/* bnz_t */
static mpz_t g_mpzVar391;
/* bnz_t */
static mpz_t g_mpzVar392;
/* bnz_t */
static mpz_t g_mpzVar393;
/* bnz_t */
static mpz_t g_mpzVar394;
/* bnz_t */
static mpz_t g_mpzVar395;
/* bnz_t */
static mpz_t g_mpzVar396;
/* bnz_t */
static mpz_t g_mpzVar397;
/* bnz_t */
static mpz_t g_mpzVar398;
/* bnz_t */
static mpz_t g_mpzVar399;
/* bnz_t */
static mpz_t g_mpzVar400;
/* bnz_t */
static mpz_t g_mpzVar401;
/* bnz_t */
static mpz_t g_mpzVar402;
/* bnz_t */
static mpz_t g_mpzVar403;
/* bnz_t */
static mpz_t g_mpzVar404;
/* bnz_t */
static mpz_t g_mpzVar405;
/* bnz_t */
static mpz_t g_mpzVar406;
/* bnz_t */
static mpz_t g_mpzVar407;
/* bnz_t */
static mpz_t g_mpzVar408;
/* bnz_t */
static mpz_t g_mpzVar409;
/* bnz_t */
static mpz_t g_mpzVar410;
/* bnz_t */
static mpz_t g_mpzVar411;
/* bnz_t */
static mpz_t g_mpzVar412;
/* bnz_t */
static mpz_t g_mpzVar413;
/* bnz_t */
static mpz_t g_mpzVar414;
/* bnz_t */
static mpz_t g_mpzVar415;
/* bnz_t */
static mpz_t g_mpzVar416;
/* bnz_t */
static mpz_t g_mpzVar417;
/* bnz_t */
static mpz_t g_mpzVar418;
/* bnz_t */
static mpz_t g_mpzVar419;
/* bnz_t */
static mpz_t g_mpzVar420;
/* bnz_t */
static mpz_t g_mpzVar421;
/* bnz_t */
static mpz_t g_mpzVar422;
/* bnz_t */
static mpz_t g_mpzVar423;
/* bnz_t */
static mpz_t g_mpzVar424;
/* bnz_t */
static mpz_t g_mpzVar425;
/* bnz_t */
static mpz_t g_mpzVar426;
/* bnz_t */
static mpz_t g_mpzVar427;
/* bnz_t */
static mpz_t g_mpzVar428;
/* bnz_t */
static mpz_t g_mpzVar429;
/* bnz_t */
static mpz_t g_mpzVar430;
/* bnz_t */
static mpz_t g_mpzVar431;
/* bnz_t */
static mpz_t g_mpzVar432;
/* bnz_t */
static mpz_t g_mpzVar433;
/* bnz_t */
static mpz_t g_mpzVar434;
/* bnz_t */
static mpz_t g_mpzVar435;
/* bnz_t */
static mpz_t g_mpzVar436;
/* bnz_t */
static mpz_t g_mpzVar437;
/* bnz_t */
static mpz_t g_mpzVar438;
/* bnz_t */
static mpz_t g_mpzVar439;
/* bnz_t */
static mpz_t g_mpzVar440;
/* bnz_t */
static mpz_t g_mpzVar441;
/* bnz_t */
static mpz_t g_mpzVar442;
/* bnz_t */
static mpz_t g_mpzVar443;
/* bnz_t */
static mpz_t g_mpzVar444;
/* bnz_t */
static mpz_t g_mpzVar445;
/* bnz_t */
static mpz_t g_mpzVar446;
/* bnz_t */
static mpz_t g_mpzVar447;
/* bnz_t */
static mpz_t g_mpzVar448;
/* bnz_t */
static mpz_t g_mpzVar449;
/* bnz_t */
static mpz_t g_mpzVar450;
/* bnz_t */
static mpz_t g_mpzVar451;
/* bnz_t */
static mpz_t g_mpzVar452;
/* bnz_t */
static mpz_t g_mpzVar453;
/* bnz_t */
static mpz_t g_mpzVar454;
/* bnz_t */
static mpz_t g_mpzVar455;
/* bnz_t */
static mpz_t g_mpzVar456;
/* bnz_t */
static mpz_t g_mpzVar457;
/* bnz_t */
static mpz_t g_mpzVar458;
/* bnz_t */
static mpz_t g_mpzVar459;
/* bnz_t */
static mpz_t g_mpzVar460;
/* bnz_t */
static mpz_t g_mpzVar461;
/* bnz_t */
static mpz_t g_mpzVar462;
/* bnz_t */
static mpz_t g_mpzVar463;
/* bnz_t */
static mpz_t g_mpzVar464;
/* bnz_t */
static mpz_t g_mpzVar465;
/* bnz_t */
static mpz_t g_mpzVar466;
/* bnz_t */
static mpz_t g_mpzVar467;
/* bnz_t */
static mpz_t g_mpzVar468;
/* bnz_t */
static mpz_t g_mpzVar469;
/* bnz_t */
static mpz_t g_mpzVar470;
/* bnz_t */
static mpz_t g_mpzVar471;
/* bnz_t */
static mpz_t g_mpzVar472;
/* bnz_t */
static mpz_t g_mpzVar473;
/* bnz_t */
static mpz_t g_mpzVar474;
/* bnz_t */
static mpz_t g_mpzVar475;
/* bnz_t */
static mpz_t g_mpzVar476;
/* bnz_t */
static mpz_t g_mpzVar477;
/* bnz_t */
static mpz_t g_mpzVar478;
/* bnz_t */
static mpz_t g_mpzVar479;
/* bnz_t */
static mpz_t g_mpzVar480;
/* bnz_t */
static mpz_t g_mpzVar481;
/* bnz_t */
static mpz_t g_mpzVar482;
/* bnz_t */
static mpz_t g_mpzVar483;
/* bnz_t */
static mpz_t g_mpzVar484;
/* bnz_t */
static mpz_t g_mpzVar485;
/* bnz_t */
static mpz_t g_mpzVar486;
/* bnz_t */
static mpz_t g_mpzVar487;
/* bnz_t */
static mpz_t g_mpzVar488;
/* bnz_t */
static mpz_t g_mpzVar489;
/* bnz_t */
static mpz_t g_mpzVar490;
/* bnz_t */
static mpz_t g_mpzVar491;
/* bnz_t */
static mpz_t g_mpzVar492;
/* bnz_t */
static mpz_t g_mpzVar493;

/* zk_Prover_init: sub program */
zk_bool zk_Prover_init(const mpz_t vAux_gi[1], const mpz_t vPublicCommitment_x[27], const mpz_t vSecret_w[42])
{
    /* CMV_IN(tmpMinI) */
    mpz_t mpzVar494;
    /* CMV_IN(tmpMaxI) */
    mpz_t mpzVar495;
    /* CMV_IN(tmpN) */
    mpz_t mpzVar496;
    /* CMV_IN(tmpMinI) */
    mpz_t mpzVar497;
    /* CMV_IN(tmpMaxI) */
    mpz_t mpzVar498;
    /* zk_pcchar_t */
    zk_pcchar pccVar499;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar500;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar501;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar502;
    /* zk_pcchar_t */
    zk_pcchar pccVar503;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar504;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar505;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar506;
    /* zk_pcchar_t */
    zk_pcchar pccVar507;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar508;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar509;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar510;
    /* zk_pcchar_t */
    zk_pcchar pccVar511;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar512;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar513;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar514;
    /* zk_pcchar_t */
    zk_pcchar pccVar515;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar516;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar517;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar518;
    /* zk_pcchar_t */
    zk_pcchar pccVar519;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar520;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar521;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar522;
    /* zk_pcchar_t */
    zk_pcchar pccVar523;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar524;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar525;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar526;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar527;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar528;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar529;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar530;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar531;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar532;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar533;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar534;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar535;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar536;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar537;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar538;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar539;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar540;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar541;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar542;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar543;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar544;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar545;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar546;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar547;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar548;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar549;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar550;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar551;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar552;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar553;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar554;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar555;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar556;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar557;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar558;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar559;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar560;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar561;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar562;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar563;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar564;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar565;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar566;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar567;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar568;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar569;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar570;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar571;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar572;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar573;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar574;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar575;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar576;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar577;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar578;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar579;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar580;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar581;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar582;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar583;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar584;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar585;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar586;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar587;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar588;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar589;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar590;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar591;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar592;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar593;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar594;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar595;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar596;
    /* CMV_IN(-1l) */
    zk_long lVar597;
    /* CMV_IN((unsigned) strtoul(params[4], 0, 10)) */
    zk_uint uiVar598;
    /* CMV_IN(cp) */
    mpz_t mpzVar599;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar600;
    
    /* construct [z.cpp:27: mini] */
    /* construct [z.cpp:27: maxi] */
    /* construct [z.cpp:27: minitight] */
    /* construct [z.cpp:27: maxitight] */
    /* construct [z.cpp:47: CMV_IN(tmpMinI)] */
    mpz_init_set_str(mpzVar494, "-1461501637330902918203684832716283019655932542976", 10);
    /* bnz_init_set(mini, CMV_IN(tmpMinI)) */
    mpz_init_set(g_mpzVar1, mpzVar494);
    /* destruct [z.cpp:47: CMV_IN(tmpMinI)] */
    mpz_clear(mpzVar494);
    /* construct [z.cpp:49: CMV_IN(tmpMaxI)] */
    mpz_init_set_str(mpzVar495, "1461501637330902918203684832716283019655932542976", 10);
    /* bnz_init_set(maxi, CMV_IN(tmpMaxI)) */
    mpz_init_set(g_mpzVar2, mpzVar495);
    /* destruct [z.cpp:49: CMV_IN(tmpMaxI)] */
    mpz_clear(mpzVar495);
    /* bnz_init(minitight) */
    mpz_init(g_mpzVar3);
    /* bnz_init(maxitight) */
    mpz_init(g_mpzVar4);
    /* construct [z_mul_n.cpp:32: n] */
    /* construct [z_mul_n.cpp:53: CMV_IN(tmpN)] */
    mpz_init_set_str(mpzVar496, "2835709", 10);
    /* bnz_init_set(n, CMV_IN(tmpN)) */
    mpz_init_set(g_mpzVar5, mpzVar496);
    /* destruct [z_mul_n.cpp:53: CMV_IN(tmpN)] */
    mpz_clear(mpzVar496);
    /* construct [z.cpp:27: mini] */
    /* construct [z.cpp:27: maxi] */
    /* construct [z.cpp:27: minitight] */
    /* construct [z.cpp:27: maxitight] */
    /* construct [z.cpp:47: CMV_IN(tmpMinI)] */
    mpz_init_set_str(mpzVar497, "0", 10);
    /* bnz_init_set(mini, CMV_IN(tmpMinI)) */
    mpz_init_set(g_mpzVar6, mpzVar497);
    /* destruct [z.cpp:47: CMV_IN(tmpMinI)] */
    mpz_clear(mpzVar497);
    /* construct [z.cpp:49: CMV_IN(tmpMaxI)] */
    mpz_init_set_str(mpzVar498, "0", 10);
    /* bnz_init_set(maxi, CMV_IN(tmpMaxI)) */
    mpz_init_set(g_mpzVar7, mpzVar498);
    /* destruct [z.cpp:49: CMV_IN(tmpMaxI)] */
    mpz_clear(mpzVar498);
    /* bnz_init(minitight) */
    mpz_init(g_mpzVar8);
    /* bnz_init(maxitight) */
    mpz_init(g_mpzVar9);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar10);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar500 = "1000";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar499 = pccVar500;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar601;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar602;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar601 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar602 = mpz_set_str(g_mpzVar10, pccVar499, iVar601);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar501 = (zk_bool)iVar602;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar501)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar603;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar604;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar605;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar603 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar604 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar605 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar605, pccVar604, iVar603, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:227: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] */
    }
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar606;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar607;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar606 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar607 = !bVar606;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar502 = (zk_bool)bVar607;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar502)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar608;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar609;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar610;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar608 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar609 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar610 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar610, pccVar609, iVar608, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:231: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] */
    }
    /* destruct [parser.cpp:211: zk_pcchar_t] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar11);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar504 = "99999";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar503 = pccVar504;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar611;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar612;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar611 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar612 = mpz_set_str(g_mpzVar11, pccVar503, iVar611);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar505 = (zk_bool)iVar612;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar505)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar613;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar614;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar615;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar613 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar614 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar615 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar615, pccVar614, iVar613, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:227: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] */
    }
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar616;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar617;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar616 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar617 = !bVar616;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar506 = (zk_bool)bVar617;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar506)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar618;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar619;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar620;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar618 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar619 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar620 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar620, pccVar619, iVar618, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:231: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] */
    }
    /* destruct [parser.cpp:211: zk_pcchar_t] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar12);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar508 = "1434019";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar507 = pccVar508;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar621;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar622;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar621 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar622 = mpz_set_str(g_mpzVar12, pccVar507, iVar621);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar509 = (zk_bool)iVar622;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar509)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar623;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar624;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar625;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar623 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar624 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar625 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar625, pccVar624, iVar623, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:227: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] */
    }
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar626;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar627;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar628;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar629;
            /* CMV_IN(1ul) */
            zk_ulong ulVar630;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar631;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar632;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar629 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar630 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar631 = mpz_cmp_ui(g_mpzVar12, ulVar630);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar632 = iVar631 < iVar629;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar628 = (zk_bool)bVar632;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar628)
            {
                /* CMV_IN(false) */
                zk_bool bVar633;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar633 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar626 = (zk_bool)bVar633;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar634;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar635;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar636;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar637;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar635 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar636 = mpz_cmp(g_mpzVar12, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar637 = iVar636 >= iVar635;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar634 = (zk_bool)bVar637;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar634)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar638;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar638 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar626 = (zk_bool)bVar638;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar639;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar640;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar639);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar639, g_mpzVar12, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar641;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar642;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar643;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar644;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar641 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar642 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar643 = mpz_cmp_ui(mpzVar639, ulVar642);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar644 = iVar643 == iVar641;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar640 = (zk_bool)bVar644;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar640)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar645;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar645 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar626 = (zk_bool)bVar645;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar646;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar646 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar626 = (zk_bool)bVar646;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar639);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar627 = !bVar626;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar510 = (zk_bool)bVar627;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar510)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar647;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar648;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar649;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar647 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar648 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar649 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar649, pccVar648, iVar647, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:231: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] */
    }
    /* destruct [parser.cpp:211: zk_pcchar_t] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar13);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar512 = "1321157";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar511 = pccVar512;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar650;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar651;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar650 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar651 = mpz_set_str(g_mpzVar13, pccVar511, iVar650);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar513 = (zk_bool)iVar651;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar513)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar652;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar653;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar654;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar652 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar653 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar654 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar654, pccVar653, iVar652, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:227: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] */
    }
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar655;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar656;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar657;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar658;
            /* CMV_IN(1ul) */
            zk_ulong ulVar659;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar660;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar661;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar658 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar659 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar660 = mpz_cmp_ui(g_mpzVar13, ulVar659);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar661 = iVar660 < iVar658;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar657 = (zk_bool)bVar661;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar657)
            {
                /* CMV_IN(false) */
                zk_bool bVar662;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar662 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar655 = (zk_bool)bVar662;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar663;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar664;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar665;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar666;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar664 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar665 = mpz_cmp(g_mpzVar13, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar666 = iVar665 >= iVar664;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar663 = (zk_bool)bVar666;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar663)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar667;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar667 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar655 = (zk_bool)bVar667;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar668;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar669;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar668);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar668, g_mpzVar13, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar670;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar671;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar672;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar673;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar670 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar671 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar672 = mpz_cmp_ui(mpzVar668, ulVar671);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar673 = iVar672 == iVar670;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar669 = (zk_bool)bVar673;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar669)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar674;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar674 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar655 = (zk_bool)bVar674;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar675;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar675 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar655 = (zk_bool)bVar675;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar668);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar656 = !bVar655;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar514 = (zk_bool)bVar656;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar514)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar676;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar677;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar678;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar676 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar677 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar678 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar678, pccVar677, iVar676, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:231: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] */
    }
    /* destruct [parser.cpp:211: zk_pcchar_t] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar14);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar516 = "2128741";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar515 = pccVar516;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar679;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar680;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar679 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar680 = mpz_set_str(g_mpzVar14, pccVar515, iVar679);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar517 = (zk_bool)iVar680;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar517)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar681;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar682;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar683;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar681 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar682 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar683 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar683, pccVar682, iVar681, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:227: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] */
    }
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar684;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar685;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar686;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar687;
            /* CMV_IN(1ul) */
            zk_ulong ulVar688;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar689;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar690;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar687 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar688 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar689 = mpz_cmp_ui(g_mpzVar14, ulVar688);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar690 = iVar689 < iVar687;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar686 = (zk_bool)bVar690;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar686)
            {
                /* CMV_IN(false) */
                zk_bool bVar691;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar691 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar684 = (zk_bool)bVar691;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar692;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar693;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar694;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar695;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar693 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar694 = mpz_cmp(g_mpzVar14, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar695 = iVar694 >= iVar693;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar692 = (zk_bool)bVar695;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar692)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar696;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar696 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar684 = (zk_bool)bVar696;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar697;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar698;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar697);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar697, g_mpzVar14, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar699;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar700;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar701;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar702;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar699 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar700 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar701 = mpz_cmp_ui(mpzVar697, ulVar700);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar702 = iVar701 == iVar699;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar698 = (zk_bool)bVar702;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar698)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar703;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar703 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar684 = (zk_bool)bVar703;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar704;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar704 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar684 = (zk_bool)bVar704;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar697);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar685 = !bVar684;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar518 = (zk_bool)bVar685;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar518)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar705;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar706;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar707;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar705 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar706 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar707 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar707, pccVar706, iVar705, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:231: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] */
    }
    /* destruct [parser.cpp:211: zk_pcchar_t] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar15);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar520 = "797470";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar519 = pccVar520;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar708;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar709;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar708 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar709 = mpz_set_str(g_mpzVar15, pccVar519, iVar708);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar521 = (zk_bool)iVar709;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar521)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar710;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar711;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar712;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar710 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar711 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar712 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar712, pccVar711, iVar710, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:227: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] */
    }
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar713;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar714;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar715;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar716;
            /* CMV_IN(1ul) */
            zk_ulong ulVar717;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar718;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar719;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar716 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar717 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar718 = mpz_cmp_ui(g_mpzVar15, ulVar717);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar719 = iVar718 < iVar716;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar715 = (zk_bool)bVar719;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar715)
            {
                /* CMV_IN(false) */
                zk_bool bVar720;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar720 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar713 = (zk_bool)bVar720;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar721;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar722;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar723;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar724;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar722 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar723 = mpz_cmp(g_mpzVar15, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar724 = iVar723 >= iVar722;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar721 = (zk_bool)bVar724;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar721)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar725;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar725 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar713 = (zk_bool)bVar725;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar726;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar727;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar726);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar726, g_mpzVar15, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar728;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar729;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar730;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar731;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar728 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar729 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar730 = mpz_cmp_ui(mpzVar726, ulVar729);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar731 = iVar730 == iVar728;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar727 = (zk_bool)bVar731;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar727)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar732;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar732 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar713 = (zk_bool)bVar732;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar733;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar733 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar713 = (zk_bool)bVar733;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar726);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar714 = !bVar713;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar522 = (zk_bool)bVar714;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar522)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar734;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar735;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar736;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar734 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar735 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar736 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar736, pccVar735, iVar734, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:231: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] */
    }
    /* destruct [parser.cpp:211: zk_pcchar_t] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar16);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar17);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar18);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar19);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar20);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar21);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar22);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar23);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar24);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar25);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar26);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar27);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar28);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar29);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar30);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar31);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar32);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar33);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar34);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar35);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar36);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar37);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar38);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar39);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar40);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar41);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar42);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar43);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar44);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar45);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar46);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar47);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar48);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar49);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar50);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar51);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar52);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar53);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar54);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar55);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar56);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar57);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar58);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar59);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar60);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar61);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar62);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar63);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar64);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar65);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar66);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar67);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar68);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar69);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar70);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar71);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar72);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar73);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar74);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar75);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar76);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar77);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar78);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar79);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar80);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar81);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar82);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar83);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar84);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar85);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar86);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar524 = "-1";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar523 = pccVar524;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar737;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar738;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar737 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar738 = mpz_set_str(g_mpzVar86, pccVar523, iVar737);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar525 = (zk_bool)iVar738;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar525)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar739;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar740;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar741;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar739 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar740 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar741 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar741, pccVar740, iVar739, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            /* destruct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:227: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] */
    }
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar742;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar743;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar742 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar743 = !bVar742;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar526 = (zk_bool)bVar743;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar526)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar744;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar745;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar746;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar744 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar745 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar746 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar746, pccVar745, iVar744, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:231: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] */
    }
    /* destruct [parser.cpp:211: zk_pcchar_t] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar87);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar88);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar89);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar90);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar91);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar92);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar93);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar94);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar95);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar96);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar97);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar98);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar99);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar100);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar101);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar102);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar103);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar104);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar105);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar106);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar107);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar108);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar109);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar110);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar111);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar112);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar113);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar114);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar115);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar116);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar117);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar118);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar119);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar120);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar121);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar122);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar123);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar124);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar125);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar126);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar127);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar128);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar129);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar130);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar131);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar132);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar133);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar134);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar135);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar136);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar137);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar138);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar139);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar140);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar141);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar142);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar143);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar144);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar145);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar146);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar147);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar148);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar149);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar150);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar151);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar152);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar153);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar154);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar155);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar156);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar157);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar158);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar159);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar160);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar161);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar162);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar163);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar164);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar165);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar166);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar167);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar168);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar169);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar170);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar171);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar172);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar173);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar174);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar175);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar176);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar177);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar178);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar179);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar180);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar181);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar182);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar183);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar184);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar185);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar186);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar187);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar188);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar189);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar190);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar191);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar192);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar193);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar194);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar195);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar196);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar197);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar198);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar199);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar200);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar201);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar202);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar203);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar204);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar205);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar206);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar207);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar208);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar209);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar210);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar211);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar212);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar213);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar214);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar215);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar216);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar217);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar218);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar219);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar220);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar221);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar222);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar223);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar224);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar225);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar226);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar227);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar228);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar229);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar230);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar231);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar232);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar233);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar234);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar235);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar236);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar237);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar238);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar239);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar240);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar241);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar242);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar243);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar244);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar245);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar246);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar247);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar248);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar249);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar250);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar251);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar252);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar253);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar254);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar255);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar256);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar257);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar258);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar259);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar260);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar261);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar262);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar263);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar264);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar265);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar266);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar267);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar268);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar269);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar270);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar271);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar272);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar273);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar274);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar275);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar276);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar277);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar278);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar279);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar280);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar281);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar282);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar283);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar284);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar285);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar286);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar287);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar288);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar289);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar290);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar291);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar292);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar293);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar294);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar295);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar296);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar297);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar298);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar299);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar300);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar301);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar302);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar303);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar304);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar305);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar306);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar307);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar308);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar309);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar310);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar311);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar312);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar313);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar314);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar315);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar316);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar317);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar318);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar319);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar320);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar321);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar322);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar323);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar324);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar325);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar326);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar327);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar328);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar329);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar330);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar331);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar332);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar333);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar334);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar335);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar336);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar337);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar338);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar339);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar340);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar341);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar342);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar343);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar344);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar345);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar346);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar347);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar348);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar349);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar350);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar351);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar352);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar353);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar354);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar355);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar356);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar357);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar358);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar359);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar360);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar361);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar362);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar363);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar364);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar365);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar366);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar367);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar368);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar369);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar370);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar371);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar372);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar373);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar374);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar375);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar376);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar377);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar378);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar379);
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar17, vSecret_w[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar748;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar749;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar748 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar749 = !bVar748;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar527 = (zk_bool)bVar749;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar527)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar750;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar751;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar752;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar750 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar751 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar752 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar752, pccVar751, iVar750, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar18, vSecret_w[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar754;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar755;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar754 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar755 = !bVar754;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar528 = (zk_bool)bVar755;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar528)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar756;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar757;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar758;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar756 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar757 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar758 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar758, pccVar757, iVar756, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar19, vSecret_w[2]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar760;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar761;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar760 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar761 = !bVar760;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar529 = (zk_bool)bVar761;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar529)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar762;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar763;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar764;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar762 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar763 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar764 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar764, pccVar763, iVar762, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar20, vSecret_w[3]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar766;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar767;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar766 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar767 = !bVar766;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar530 = (zk_bool)bVar767;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar530)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar768;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar769;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar770;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar768 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar769 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar770 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar770, pccVar769, iVar768, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar21, vSecret_w[4]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar772;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar773;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar772 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar773 = !bVar772;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar531 = (zk_bool)bVar773;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar531)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar774;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar775;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar776;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar774 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar775 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar776 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar776, pccVar775, iVar774, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar22, vSecret_w[5]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar778;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar779;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar778 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar779 = !bVar778;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar532 = (zk_bool)bVar779;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar532)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar780;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar781;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar782;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar780 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar781 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar782 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar782, pccVar781, iVar780, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar23, vSecret_w[6]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar784;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar785;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar784 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar785 = !bVar784;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar533 = (zk_bool)bVar785;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar533)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar786;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar787;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar788;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar786 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar787 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar788 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar788, pccVar787, iVar786, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar24, vSecret_w[7]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar790;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar791;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar790 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar791 = !bVar790;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar534 = (zk_bool)bVar791;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar534)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar792;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar793;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar794;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar792 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar793 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar794 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar794, pccVar793, iVar792, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar25, vSecret_w[8]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar796;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar797;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar796 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar797 = !bVar796;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar535 = (zk_bool)bVar797;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar535)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar798;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar799;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar800;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar798 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar799 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar800 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar800, pccVar799, iVar798, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar26, vSecret_w[9]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar802;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar803;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar802 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar803 = !bVar802;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar536 = (zk_bool)bVar803;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar536)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar804;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar805;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar806;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar804 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar805 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar806 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar806, pccVar805, iVar804, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar27, vSecret_w[10]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar808;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar809;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar808 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar809 = !bVar808;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar537 = (zk_bool)bVar809;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar537)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar810;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar811;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar812;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar810 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar811 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar812 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar812, pccVar811, iVar810, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar28, vSecret_w[11]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar814;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar815;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar814 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar815 = !bVar814;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar538 = (zk_bool)bVar815;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar538)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar816;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar817;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar818;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar816 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar817 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar818 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar818, pccVar817, iVar816, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar29, vSecret_w[12]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar820;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar821;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar820 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar821 = !bVar820;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar539 = (zk_bool)bVar821;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar539)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar822;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar823;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar824;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar822 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar823 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar824 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar824, pccVar823, iVar822, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar30, vSecret_w[13]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar826;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar827;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar826 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar827 = !bVar826;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar540 = (zk_bool)bVar827;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar540)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar828;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar829;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar830;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar828 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar829 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar830 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar830, pccVar829, iVar828, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar31, vSecret_w[14]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar832;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar833;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar832 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar833 = !bVar832;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar541 = (zk_bool)bVar833;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar541)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar834;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar835;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar836;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar834 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar835 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar836 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar836, pccVar835, iVar834, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar32, vSecret_w[15]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar838;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar839;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar838 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar839 = !bVar838;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar542 = (zk_bool)bVar839;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar542)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar840;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar841;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar842;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar840 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar841 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar842 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar842, pccVar841, iVar840, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar33, vSecret_w[16]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar844;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar845;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar844 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar845 = !bVar844;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar543 = (zk_bool)bVar845;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar543)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar846;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar847;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar848;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar846 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar847 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar848 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar848, pccVar847, iVar846, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar34, vSecret_w[17]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar850;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar851;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar850 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar851 = !bVar850;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar544 = (zk_bool)bVar851;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar544)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar852;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar853;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar854;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar852 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar853 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar854 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar854, pccVar853, iVar852, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar35, vSecret_w[18]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar856;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar857;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar856 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar857 = !bVar856;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar545 = (zk_bool)bVar857;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar545)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar858;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar859;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar860;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar858 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar859 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar860 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar860, pccVar859, iVar858, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar36, vSecret_w[19]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar862;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar863;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar862 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar863 = !bVar862;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar546 = (zk_bool)bVar863;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar546)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar864;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar865;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar866;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar864 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar865 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar866 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar866, pccVar865, iVar864, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar37, vSecret_w[20]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar868;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar869;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar868 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar869 = !bVar868;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar547 = (zk_bool)bVar869;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar547)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar870;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar871;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar872;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar870 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar871 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar872 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar872, pccVar871, iVar870, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar38, vSecret_w[21]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar874;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar875;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar874 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar875 = !bVar874;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar548 = (zk_bool)bVar875;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar548)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar876;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar877;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar878;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar876 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar877 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar878 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar878, pccVar877, iVar876, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar39, vSecret_w[22]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar880;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar881;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar880 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar881 = !bVar880;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar549 = (zk_bool)bVar881;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar549)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar882;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar883;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar884;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar882 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar883 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar884 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar884, pccVar883, iVar882, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar40, vSecret_w[23]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar886;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar887;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar886 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar887 = !bVar886;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar550 = (zk_bool)bVar887;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar550)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar888;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar889;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar890;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar888 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar889 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar890 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar890, pccVar889, iVar888, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar41, vSecret_w[24]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar892;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar893;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar892 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar893 = !bVar892;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar551 = (zk_bool)bVar893;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar551)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar894;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar895;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar896;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar894 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar895 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar896 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar896, pccVar895, iVar894, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar42, vSecret_w[25]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar898;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar899;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar898 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar899 = !bVar898;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar552 = (zk_bool)bVar899;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar552)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar900;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar901;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar902;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar900 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar901 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar902 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar902, pccVar901, iVar900, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar43, vSecret_w[26]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar904;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar905;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar904 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar905 = !bVar904;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar553 = (zk_bool)bVar905;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar553)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar906;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar907;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar908;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar906 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar907 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar908 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar908, pccVar907, iVar906, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar44, vSecret_w[27]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar910;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar911;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar910 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar911 = !bVar910;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar554 = (zk_bool)bVar911;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar554)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar912;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar913;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar914;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar912 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar913 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar914 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar914, pccVar913, iVar912, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar45, vSecret_w[28]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar916;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar917;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar916 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar917 = !bVar916;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar555 = (zk_bool)bVar917;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar555)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar918;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar919;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar920;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar918 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar919 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar920 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar920, pccVar919, iVar918, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar46, vSecret_w[29]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar922;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar923;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar922 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar923 = !bVar922;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar556 = (zk_bool)bVar923;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar556)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar924;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar925;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar926;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar924 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar925 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar926 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar926, pccVar925, iVar924, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar47, vSecret_w[30]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar928;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar929;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar928 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar929 = !bVar928;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar557 = (zk_bool)bVar929;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar557)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar930;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar931;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar932;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar930 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar931 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar932 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar932, pccVar931, iVar930, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar48, vSecret_w[31]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar934;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar935;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar934 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar935 = !bVar934;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar558 = (zk_bool)bVar935;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar558)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar936;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar937;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar938;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar936 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar937 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar938 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar938, pccVar937, iVar936, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar49, vSecret_w[32]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar940;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar941;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar940 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar941 = !bVar940;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar559 = (zk_bool)bVar941;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar559)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar942;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar943;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar944;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar942 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar943 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar944 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar944, pccVar943, iVar942, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar50, vSecret_w[33]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar946;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar947;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar946 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar947 = !bVar946;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar560 = (zk_bool)bVar947;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar560)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar948;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar949;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar950;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar948 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar949 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar950 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar950, pccVar949, iVar948, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar51, vSecret_w[34]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar952;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar953;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar952 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar953 = !bVar952;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar561 = (zk_bool)bVar953;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar561)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar954;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar955;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar956;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar954 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar955 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar956 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar956, pccVar955, iVar954, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar52, vSecret_w[35]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar958;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar959;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar958 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar959 = !bVar958;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar562 = (zk_bool)bVar959;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar562)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar960;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar961;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar962;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar960 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar961 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar962 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar962, pccVar961, iVar960, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar53, vSecret_w[36]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar964;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar965;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar964 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar965 = !bVar964;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar563 = (zk_bool)bVar965;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar563)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar966;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar967;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar968;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar966 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar967 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar968 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar968, pccVar967, iVar966, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar54, vSecret_w[37]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar970;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar971;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar970 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar971 = !bVar970;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar564 = (zk_bool)bVar971;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar564)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar972;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar973;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar974;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar972 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar973 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar974 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar974, pccVar973, iVar972, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar55, vSecret_w[38]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar976;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar977;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar976 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar977 = !bVar976;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar565 = (zk_bool)bVar977;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar565)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar978;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar979;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar980;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar978 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar979 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar980 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar980, pccVar979, iVar978, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar56, vSecret_w[39]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar982;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar983;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar982 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar983 = !bVar982;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar566 = (zk_bool)bVar983;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar566)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar984;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar985;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar986;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar984 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar985 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar986 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar986, pccVar985, iVar984, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar57, vSecret_w[40]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar988;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar989;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar988 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar989 = !bVar988;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar567 = (zk_bool)bVar989;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar567)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar990;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar991;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar992;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar990 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar991 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar992 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar992, pccVar991, iVar990, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar58, vSecret_w[41]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* CMV_IN(true) */
        zk_bool bVar994;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar995;
        
        /* construct [z.cpp:142: CMV_IN(true)] */
        bVar994 = zk_true;
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar995 = !bVar994;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar568 = (zk_bool)bVar995;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z.cpp:142: CMV_IN(true)] */
        if (bVar568)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar996;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar997;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar998;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar996 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar997 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar998 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar998, pccVar997, iVar996, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar59, vPublicCommitment_x[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1000;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1001;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1002;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1003;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1004;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1005;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1006;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1003 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1004 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1005 = mpz_cmp_ui(g_mpzVar59, ulVar1004);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1006 = iVar1005 < iVar1003;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1002 = (zk_bool)bVar1006;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1002)
            {
                /* CMV_IN(false) */
                zk_bool bVar1007;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1007 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1000 = (zk_bool)bVar1007;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1008;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1009;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1010;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1011;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1009 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1010 = mpz_cmp(g_mpzVar59, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1011 = iVar1010 >= iVar1009;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1008 = (zk_bool)bVar1011;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1008)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1012;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1012 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1000 = (zk_bool)bVar1012;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1013;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1014;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1013);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1013, g_mpzVar59, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1015;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1016;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1017;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1018;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1015 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1016 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1017 = mpz_cmp_ui(mpzVar1013, ulVar1016);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1018 = iVar1017 == iVar1015;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1014 = (zk_bool)bVar1018;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1014)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1019;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1019 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1000 = (zk_bool)bVar1019;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1020;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1020 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1000 = (zk_bool)bVar1020;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1013);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1001 = !bVar1000;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar569 = (zk_bool)bVar1001;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar569)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1021;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1022;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1023;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1021 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1022 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1023 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1023, pccVar1022, iVar1021, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar60, vPublicCommitment_x[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1025;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1026;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1027;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1028;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1029;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1030;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1031;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1028 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1029 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1030 = mpz_cmp_ui(g_mpzVar60, ulVar1029);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1031 = iVar1030 < iVar1028;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1027 = (zk_bool)bVar1031;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1027)
            {
                /* CMV_IN(false) */
                zk_bool bVar1032;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1032 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1025 = (zk_bool)bVar1032;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1033;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1034;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1035;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1036;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1034 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1035 = mpz_cmp(g_mpzVar60, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1036 = iVar1035 >= iVar1034;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1033 = (zk_bool)bVar1036;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1033)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1037;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1037 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1025 = (zk_bool)bVar1037;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1038;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1039;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1038);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1038, g_mpzVar60, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1040;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1041;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1042;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1043;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1040 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1041 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1042 = mpz_cmp_ui(mpzVar1038, ulVar1041);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1043 = iVar1042 == iVar1040;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1039 = (zk_bool)bVar1043;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1039)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1044;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1044 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1025 = (zk_bool)bVar1044;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1045;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1045 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1025 = (zk_bool)bVar1045;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1038);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1026 = !bVar1025;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar570 = (zk_bool)bVar1026;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar570)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1046;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1047;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1048;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1046 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1047 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1048 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1048, pccVar1047, iVar1046, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar61, vPublicCommitment_x[2]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1050;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1051;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1052;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1053;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1054;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1055;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1056;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1053 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1054 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1055 = mpz_cmp_ui(g_mpzVar61, ulVar1054);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1056 = iVar1055 < iVar1053;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1052 = (zk_bool)bVar1056;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1052)
            {
                /* CMV_IN(false) */
                zk_bool bVar1057;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1057 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1050 = (zk_bool)bVar1057;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1058;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1059;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1060;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1061;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1059 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1060 = mpz_cmp(g_mpzVar61, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1061 = iVar1060 >= iVar1059;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1058 = (zk_bool)bVar1061;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1058)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1062;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1062 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1050 = (zk_bool)bVar1062;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1063;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1064;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1063);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1063, g_mpzVar61, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1065;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1066;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1067;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1068;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1065 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1066 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1067 = mpz_cmp_ui(mpzVar1063, ulVar1066);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1068 = iVar1067 == iVar1065;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1064 = (zk_bool)bVar1068;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1064)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1069;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1069 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1050 = (zk_bool)bVar1069;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1070;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1070 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1050 = (zk_bool)bVar1070;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1063);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1051 = !bVar1050;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar571 = (zk_bool)bVar1051;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar571)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1071;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1072;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1073;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1071 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1072 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1073 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1073, pccVar1072, iVar1071, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar62, vPublicCommitment_x[3]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1075;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1076;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1077;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1078;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1079;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1080;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1081;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1078 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1079 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1080 = mpz_cmp_ui(g_mpzVar62, ulVar1079);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1081 = iVar1080 < iVar1078;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1077 = (zk_bool)bVar1081;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1077)
            {
                /* CMV_IN(false) */
                zk_bool bVar1082;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1082 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1075 = (zk_bool)bVar1082;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1083;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1084;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1085;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1086;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1084 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1085 = mpz_cmp(g_mpzVar62, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1086 = iVar1085 >= iVar1084;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1083 = (zk_bool)bVar1086;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1083)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1087;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1087 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1075 = (zk_bool)bVar1087;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1088;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1089;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1088);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1088, g_mpzVar62, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1090;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1091;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1092;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1093;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1090 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1091 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1092 = mpz_cmp_ui(mpzVar1088, ulVar1091);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1093 = iVar1092 == iVar1090;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1089 = (zk_bool)bVar1093;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1089)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1094;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1094 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1075 = (zk_bool)bVar1094;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1095;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1095 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1075 = (zk_bool)bVar1095;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1088);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1076 = !bVar1075;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar572 = (zk_bool)bVar1076;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar572)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1096;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1097;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1098;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1096 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1097 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1098 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1098, pccVar1097, iVar1096, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar63, vPublicCommitment_x[4]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1100;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1101;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1102;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1103;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1104;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1105;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1106;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1103 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1104 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1105 = mpz_cmp_ui(g_mpzVar63, ulVar1104);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1106 = iVar1105 < iVar1103;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1102 = (zk_bool)bVar1106;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1102)
            {
                /* CMV_IN(false) */
                zk_bool bVar1107;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1107 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1100 = (zk_bool)bVar1107;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1108;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1109;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1110;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1111;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1109 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1110 = mpz_cmp(g_mpzVar63, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1111 = iVar1110 >= iVar1109;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1108 = (zk_bool)bVar1111;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1108)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1112;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1112 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1100 = (zk_bool)bVar1112;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1113;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1114;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1113);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1113, g_mpzVar63, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1115;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1116;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1117;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1118;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1115 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1116 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1117 = mpz_cmp_ui(mpzVar1113, ulVar1116);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1118 = iVar1117 == iVar1115;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1114 = (zk_bool)bVar1118;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1114)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1119;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1119 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1100 = (zk_bool)bVar1119;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1120;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1120 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1100 = (zk_bool)bVar1120;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1113);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1101 = !bVar1100;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar573 = (zk_bool)bVar1101;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar573)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1121;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1122;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1123;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1121 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1122 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1123 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1123, pccVar1122, iVar1121, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar64, vPublicCommitment_x[5]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1125;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1126;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1127;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1128;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1129;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1130;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1131;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1128 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1129 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1130 = mpz_cmp_ui(g_mpzVar64, ulVar1129);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1131 = iVar1130 < iVar1128;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1127 = (zk_bool)bVar1131;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1127)
            {
                /* CMV_IN(false) */
                zk_bool bVar1132;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1132 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1125 = (zk_bool)bVar1132;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1133;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1134;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1135;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1136;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1134 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1135 = mpz_cmp(g_mpzVar64, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1136 = iVar1135 >= iVar1134;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1133 = (zk_bool)bVar1136;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1133)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1137;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1137 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1125 = (zk_bool)bVar1137;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1138;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1139;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1138);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1138, g_mpzVar64, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1140;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1141;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1142;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1143;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1140 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1141 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1142 = mpz_cmp_ui(mpzVar1138, ulVar1141);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1143 = iVar1142 == iVar1140;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1139 = (zk_bool)bVar1143;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1139)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1144;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1144 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1125 = (zk_bool)bVar1144;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1145;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1145 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1125 = (zk_bool)bVar1145;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1138);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1126 = !bVar1125;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar574 = (zk_bool)bVar1126;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar574)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1146;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1147;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1148;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1146 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1147 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1148 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1148, pccVar1147, iVar1146, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar65, vPublicCommitment_x[6]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1150;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1151;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1152;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1153;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1154;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1155;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1156;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1153 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1154 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1155 = mpz_cmp_ui(g_mpzVar65, ulVar1154);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1156 = iVar1155 < iVar1153;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1152 = (zk_bool)bVar1156;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1152)
            {
                /* CMV_IN(false) */
                zk_bool bVar1157;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1157 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1150 = (zk_bool)bVar1157;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1158;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1159;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1160;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1161;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1159 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1160 = mpz_cmp(g_mpzVar65, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1161 = iVar1160 >= iVar1159;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1158 = (zk_bool)bVar1161;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1158)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1162;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1162 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1150 = (zk_bool)bVar1162;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1163;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1164;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1163);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1163, g_mpzVar65, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1165;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1166;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1167;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1168;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1165 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1166 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1167 = mpz_cmp_ui(mpzVar1163, ulVar1166);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1168 = iVar1167 == iVar1165;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1164 = (zk_bool)bVar1168;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1164)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1169;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1169 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1150 = (zk_bool)bVar1169;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1170;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1170 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1150 = (zk_bool)bVar1170;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1163);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1151 = !bVar1150;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar575 = (zk_bool)bVar1151;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar575)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1171;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1172;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1173;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1171 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1172 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1173 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1173, pccVar1172, iVar1171, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar66, vPublicCommitment_x[7]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1175;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1176;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1177;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1178;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1179;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1180;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1181;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1178 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1179 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1180 = mpz_cmp_ui(g_mpzVar66, ulVar1179);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1181 = iVar1180 < iVar1178;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1177 = (zk_bool)bVar1181;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1177)
            {
                /* CMV_IN(false) */
                zk_bool bVar1182;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1182 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1175 = (zk_bool)bVar1182;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1183;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1184;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1185;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1186;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1184 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1185 = mpz_cmp(g_mpzVar66, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1186 = iVar1185 >= iVar1184;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1183 = (zk_bool)bVar1186;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1183)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1187;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1187 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1175 = (zk_bool)bVar1187;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1188;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1189;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1188);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1188, g_mpzVar66, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1190;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1191;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1192;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1193;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1190 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1191 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1192 = mpz_cmp_ui(mpzVar1188, ulVar1191);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1193 = iVar1192 == iVar1190;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1189 = (zk_bool)bVar1193;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1189)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1194;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1194 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1175 = (zk_bool)bVar1194;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1195;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1195 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1175 = (zk_bool)bVar1195;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1188);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1176 = !bVar1175;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar576 = (zk_bool)bVar1176;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar576)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1196;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1197;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1198;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1196 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1197 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1198 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1198, pccVar1197, iVar1196, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar67, vPublicCommitment_x[8]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1200;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1201;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1202;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1203;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1204;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1205;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1206;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1203 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1204 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1205 = mpz_cmp_ui(g_mpzVar67, ulVar1204);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1206 = iVar1205 < iVar1203;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1202 = (zk_bool)bVar1206;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1202)
            {
                /* CMV_IN(false) */
                zk_bool bVar1207;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1207 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1200 = (zk_bool)bVar1207;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1208;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1209;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1210;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1211;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1209 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1210 = mpz_cmp(g_mpzVar67, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1211 = iVar1210 >= iVar1209;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1208 = (zk_bool)bVar1211;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1208)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1212;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1212 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1200 = (zk_bool)bVar1212;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1213;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1214;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1213);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1213, g_mpzVar67, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1215;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1216;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1217;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1218;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1215 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1216 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1217 = mpz_cmp_ui(mpzVar1213, ulVar1216);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1218 = iVar1217 == iVar1215;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1214 = (zk_bool)bVar1218;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1214)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1219;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1219 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1200 = (zk_bool)bVar1219;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1220;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1220 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1200 = (zk_bool)bVar1220;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1213);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1201 = !bVar1200;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar577 = (zk_bool)bVar1201;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar577)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1221;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1222;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1223;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1221 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1222 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1223 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1223, pccVar1222, iVar1221, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar68, vPublicCommitment_x[9]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1225;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1226;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1227;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1228;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1229;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1230;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1231;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1228 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1229 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1230 = mpz_cmp_ui(g_mpzVar68, ulVar1229);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1231 = iVar1230 < iVar1228;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1227 = (zk_bool)bVar1231;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1227)
            {
                /* CMV_IN(false) */
                zk_bool bVar1232;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1232 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1225 = (zk_bool)bVar1232;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1233;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1234;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1235;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1236;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1234 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1235 = mpz_cmp(g_mpzVar68, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1236 = iVar1235 >= iVar1234;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1233 = (zk_bool)bVar1236;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1233)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1237;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1237 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1225 = (zk_bool)bVar1237;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1238;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1239;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1238);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1238, g_mpzVar68, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1240;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1241;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1242;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1243;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1240 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1241 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1242 = mpz_cmp_ui(mpzVar1238, ulVar1241);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1243 = iVar1242 == iVar1240;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1239 = (zk_bool)bVar1243;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1239)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1244;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1244 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1225 = (zk_bool)bVar1244;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1245;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1245 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1225 = (zk_bool)bVar1245;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1238);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1226 = !bVar1225;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar578 = (zk_bool)bVar1226;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar578)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1246;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1247;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1248;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1246 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1247 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1248 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1248, pccVar1247, iVar1246, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar69, vPublicCommitment_x[10]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1250;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1251;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1252;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1253;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1254;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1255;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1256;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1253 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1254 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1255 = mpz_cmp_ui(g_mpzVar69, ulVar1254);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1256 = iVar1255 < iVar1253;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1252 = (zk_bool)bVar1256;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1252)
            {
                /* CMV_IN(false) */
                zk_bool bVar1257;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1257 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1250 = (zk_bool)bVar1257;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1258;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1259;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1260;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1261;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1259 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1260 = mpz_cmp(g_mpzVar69, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1261 = iVar1260 >= iVar1259;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1258 = (zk_bool)bVar1261;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1258)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1262;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1262 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1250 = (zk_bool)bVar1262;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1263;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1264;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1263);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1263, g_mpzVar69, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1265;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1266;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1267;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1268;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1265 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1266 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1267 = mpz_cmp_ui(mpzVar1263, ulVar1266);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1268 = iVar1267 == iVar1265;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1264 = (zk_bool)bVar1268;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1264)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1269;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1269 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1250 = (zk_bool)bVar1269;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1270;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1270 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1250 = (zk_bool)bVar1270;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1263);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1251 = !bVar1250;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar579 = (zk_bool)bVar1251;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar579)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1271;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1272;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1273;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1271 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1272 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1273 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1273, pccVar1272, iVar1271, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar70, vPublicCommitment_x[11]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1275;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1276;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1277;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1278;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1279;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1280;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1281;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1278 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1279 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1280 = mpz_cmp_ui(g_mpzVar70, ulVar1279);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1281 = iVar1280 < iVar1278;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1277 = (zk_bool)bVar1281;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1277)
            {
                /* CMV_IN(false) */
                zk_bool bVar1282;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1282 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1275 = (zk_bool)bVar1282;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1283;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1284;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1285;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1286;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1284 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1285 = mpz_cmp(g_mpzVar70, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1286 = iVar1285 >= iVar1284;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1283 = (zk_bool)bVar1286;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1283)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1287;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1287 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1275 = (zk_bool)bVar1287;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1288;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1289;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1288);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1288, g_mpzVar70, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1290;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1291;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1292;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1293;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1290 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1291 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1292 = mpz_cmp_ui(mpzVar1288, ulVar1291);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1293 = iVar1292 == iVar1290;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1289 = (zk_bool)bVar1293;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1289)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1294;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1294 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1275 = (zk_bool)bVar1294;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1295;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1295 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1275 = (zk_bool)bVar1295;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1288);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1276 = !bVar1275;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar580 = (zk_bool)bVar1276;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar580)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1296;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1297;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1298;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1296 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1297 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1298 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1298, pccVar1297, iVar1296, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar71, vPublicCommitment_x[12]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1300;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1301;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1302;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1303;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1304;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1305;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1306;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1303 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1304 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1305 = mpz_cmp_ui(g_mpzVar71, ulVar1304);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1306 = iVar1305 < iVar1303;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1302 = (zk_bool)bVar1306;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1302)
            {
                /* CMV_IN(false) */
                zk_bool bVar1307;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1307 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1300 = (zk_bool)bVar1307;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1308;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1309;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1310;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1311;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1309 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1310 = mpz_cmp(g_mpzVar71, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1311 = iVar1310 >= iVar1309;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1308 = (zk_bool)bVar1311;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1308)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1312;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1312 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1300 = (zk_bool)bVar1312;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1313;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1314;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1313);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1313, g_mpzVar71, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1315;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1316;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1317;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1318;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1315 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1316 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1317 = mpz_cmp_ui(mpzVar1313, ulVar1316);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1318 = iVar1317 == iVar1315;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1314 = (zk_bool)bVar1318;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1314)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1319;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1319 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1300 = (zk_bool)bVar1319;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1320;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1320 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1300 = (zk_bool)bVar1320;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1313);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1301 = !bVar1300;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar581 = (zk_bool)bVar1301;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar581)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1321;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1322;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1323;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1321 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1322 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1323 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1323, pccVar1322, iVar1321, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar72, vPublicCommitment_x[13]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1325;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1326;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1327;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1328;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1329;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1330;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1331;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1328 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1329 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1330 = mpz_cmp_ui(g_mpzVar72, ulVar1329);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1331 = iVar1330 < iVar1328;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1327 = (zk_bool)bVar1331;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1327)
            {
                /* CMV_IN(false) */
                zk_bool bVar1332;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1332 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1325 = (zk_bool)bVar1332;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1333;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1334;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1335;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1336;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1334 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1335 = mpz_cmp(g_mpzVar72, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1336 = iVar1335 >= iVar1334;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1333 = (zk_bool)bVar1336;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1333)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1337;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1337 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1325 = (zk_bool)bVar1337;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1338;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1339;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1338);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1338, g_mpzVar72, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1340;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1341;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1342;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1343;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1340 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1341 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1342 = mpz_cmp_ui(mpzVar1338, ulVar1341);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1343 = iVar1342 == iVar1340;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1339 = (zk_bool)bVar1343;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1339)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1344;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1344 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1325 = (zk_bool)bVar1344;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1345;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1345 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1325 = (zk_bool)bVar1345;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1338);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1326 = !bVar1325;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar582 = (zk_bool)bVar1326;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar582)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1346;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1347;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1348;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1346 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1347 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1348 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1348, pccVar1347, iVar1346, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar73, vPublicCommitment_x[14]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1350;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1351;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1352;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1353;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1354;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1355;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1356;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1353 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1354 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1355 = mpz_cmp_ui(g_mpzVar73, ulVar1354);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1356 = iVar1355 < iVar1353;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1352 = (zk_bool)bVar1356;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1352)
            {
                /* CMV_IN(false) */
                zk_bool bVar1357;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1357 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1350 = (zk_bool)bVar1357;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1358;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1359;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1360;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1361;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1359 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1360 = mpz_cmp(g_mpzVar73, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1361 = iVar1360 >= iVar1359;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1358 = (zk_bool)bVar1361;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1358)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1362;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1362 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1350 = (zk_bool)bVar1362;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1363;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1364;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1363);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1363, g_mpzVar73, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1365;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1366;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1367;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1368;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1365 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1366 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1367 = mpz_cmp_ui(mpzVar1363, ulVar1366);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1368 = iVar1367 == iVar1365;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1364 = (zk_bool)bVar1368;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1364)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1369;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1369 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1350 = (zk_bool)bVar1369;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1370;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1370 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1350 = (zk_bool)bVar1370;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1363);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1351 = !bVar1350;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar583 = (zk_bool)bVar1351;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar583)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1371;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1372;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1373;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1371 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1372 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1373 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1373, pccVar1372, iVar1371, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar74, vPublicCommitment_x[15]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1375;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1376;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1377;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1378;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1379;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1380;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1381;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1378 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1379 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1380 = mpz_cmp_ui(g_mpzVar74, ulVar1379);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1381 = iVar1380 < iVar1378;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1377 = (zk_bool)bVar1381;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1377)
            {
                /* CMV_IN(false) */
                zk_bool bVar1382;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1382 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1375 = (zk_bool)bVar1382;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1383;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1384;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1385;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1386;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1384 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1385 = mpz_cmp(g_mpzVar74, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1386 = iVar1385 >= iVar1384;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1383 = (zk_bool)bVar1386;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1383)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1387;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1387 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1375 = (zk_bool)bVar1387;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1388;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1389;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1388);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1388, g_mpzVar74, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1390;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1391;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1392;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1393;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1390 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1391 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1392 = mpz_cmp_ui(mpzVar1388, ulVar1391);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1393 = iVar1392 == iVar1390;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1389 = (zk_bool)bVar1393;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1389)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1394;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1394 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1375 = (zk_bool)bVar1394;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1395;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1395 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1375 = (zk_bool)bVar1395;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1388);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1376 = !bVar1375;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar584 = (zk_bool)bVar1376;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar584)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1396;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1397;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1398;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1396 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1397 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1398 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1398, pccVar1397, iVar1396, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar75, vPublicCommitment_x[16]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1400;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1401;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1402;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1403;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1404;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1405;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1406;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1403 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1404 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1405 = mpz_cmp_ui(g_mpzVar75, ulVar1404);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1406 = iVar1405 < iVar1403;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1402 = (zk_bool)bVar1406;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1402)
            {
                /* CMV_IN(false) */
                zk_bool bVar1407;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1407 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1400 = (zk_bool)bVar1407;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1408;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1409;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1410;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1411;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1409 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1410 = mpz_cmp(g_mpzVar75, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1411 = iVar1410 >= iVar1409;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1408 = (zk_bool)bVar1411;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1408)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1412;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1412 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1400 = (zk_bool)bVar1412;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1413;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1414;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1413);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1413, g_mpzVar75, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1415;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1416;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1417;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1418;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1415 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1416 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1417 = mpz_cmp_ui(mpzVar1413, ulVar1416);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1418 = iVar1417 == iVar1415;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1414 = (zk_bool)bVar1418;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1414)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1419;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1419 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1400 = (zk_bool)bVar1419;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1420;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1420 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1400 = (zk_bool)bVar1420;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1413);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1401 = !bVar1400;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar585 = (zk_bool)bVar1401;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar585)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1421;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1422;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1423;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1421 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1422 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1423 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1423, pccVar1422, iVar1421, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar76, vPublicCommitment_x[17]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1425;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1426;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1427;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1428;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1429;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1430;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1431;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1428 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1429 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1430 = mpz_cmp_ui(g_mpzVar76, ulVar1429);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1431 = iVar1430 < iVar1428;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1427 = (zk_bool)bVar1431;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1427)
            {
                /* CMV_IN(false) */
                zk_bool bVar1432;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1432 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1425 = (zk_bool)bVar1432;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1433;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1434;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1435;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1436;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1434 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1435 = mpz_cmp(g_mpzVar76, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1436 = iVar1435 >= iVar1434;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1433 = (zk_bool)bVar1436;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1433)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1437;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1437 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1425 = (zk_bool)bVar1437;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1438;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1439;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1438);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1438, g_mpzVar76, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1440;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1441;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1442;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1443;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1440 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1441 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1442 = mpz_cmp_ui(mpzVar1438, ulVar1441);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1443 = iVar1442 == iVar1440;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1439 = (zk_bool)bVar1443;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1439)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1444;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1444 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1425 = (zk_bool)bVar1444;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1445;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1445 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1425 = (zk_bool)bVar1445;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1438);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1426 = !bVar1425;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar586 = (zk_bool)bVar1426;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar586)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1446;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1447;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1448;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1446 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1447 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1448 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1448, pccVar1447, iVar1446, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar77, vPublicCommitment_x[18]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1450;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1451;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1452;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1453;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1454;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1455;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1456;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1453 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1454 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1455 = mpz_cmp_ui(g_mpzVar77, ulVar1454);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1456 = iVar1455 < iVar1453;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1452 = (zk_bool)bVar1456;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1452)
            {
                /* CMV_IN(false) */
                zk_bool bVar1457;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1457 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1450 = (zk_bool)bVar1457;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1458;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1459;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1460;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1461;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1459 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1460 = mpz_cmp(g_mpzVar77, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1461 = iVar1460 >= iVar1459;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1458 = (zk_bool)bVar1461;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1458)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1462;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1462 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1450 = (zk_bool)bVar1462;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1463;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1464;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1463);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1463, g_mpzVar77, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1465;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1466;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1467;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1468;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1465 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1466 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1467 = mpz_cmp_ui(mpzVar1463, ulVar1466);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1468 = iVar1467 == iVar1465;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1464 = (zk_bool)bVar1468;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1464)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1469;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1469 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1450 = (zk_bool)bVar1469;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1470;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1470 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1450 = (zk_bool)bVar1470;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1463);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1451 = !bVar1450;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar587 = (zk_bool)bVar1451;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar587)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1471;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1472;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1473;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1471 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1472 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1473 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1473, pccVar1472, iVar1471, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar78, vPublicCommitment_x[19]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1475;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1476;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1477;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1478;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1479;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1480;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1481;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1478 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1479 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1480 = mpz_cmp_ui(g_mpzVar78, ulVar1479);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1481 = iVar1480 < iVar1478;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1477 = (zk_bool)bVar1481;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1477)
            {
                /* CMV_IN(false) */
                zk_bool bVar1482;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1482 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1475 = (zk_bool)bVar1482;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1483;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1484;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1485;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1486;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1484 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1485 = mpz_cmp(g_mpzVar78, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1486 = iVar1485 >= iVar1484;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1483 = (zk_bool)bVar1486;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1483)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1487;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1487 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1475 = (zk_bool)bVar1487;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1488;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1489;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1488);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1488, g_mpzVar78, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1490;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1491;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1492;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1493;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1490 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1491 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1492 = mpz_cmp_ui(mpzVar1488, ulVar1491);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1493 = iVar1492 == iVar1490;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1489 = (zk_bool)bVar1493;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1489)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1494;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1494 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1475 = (zk_bool)bVar1494;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1495;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1495 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1475 = (zk_bool)bVar1495;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1488);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1476 = !bVar1475;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar588 = (zk_bool)bVar1476;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar588)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1496;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1497;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1498;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1496 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1497 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1498 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1498, pccVar1497, iVar1496, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar79, vPublicCommitment_x[20]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1500;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1501;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1502;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1503;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1504;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1505;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1506;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1503 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1504 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1505 = mpz_cmp_ui(g_mpzVar79, ulVar1504);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1506 = iVar1505 < iVar1503;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1502 = (zk_bool)bVar1506;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1502)
            {
                /* CMV_IN(false) */
                zk_bool bVar1507;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1507 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1500 = (zk_bool)bVar1507;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1508;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1509;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1510;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1511;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1509 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1510 = mpz_cmp(g_mpzVar79, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1511 = iVar1510 >= iVar1509;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1508 = (zk_bool)bVar1511;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1508)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1512;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1512 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1500 = (zk_bool)bVar1512;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1513;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1514;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1513);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1513, g_mpzVar79, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1515;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1516;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1517;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1518;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1515 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1516 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1517 = mpz_cmp_ui(mpzVar1513, ulVar1516);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1518 = iVar1517 == iVar1515;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1514 = (zk_bool)bVar1518;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1514)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1519;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1519 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1500 = (zk_bool)bVar1519;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1520;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1520 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1500 = (zk_bool)bVar1520;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1513);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1501 = !bVar1500;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar589 = (zk_bool)bVar1501;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar589)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1521;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1522;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1523;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1521 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1522 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1523 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1523, pccVar1522, iVar1521, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar80, vPublicCommitment_x[21]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1525;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1526;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1527;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1528;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1529;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1530;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1531;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1528 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1529 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1530 = mpz_cmp_ui(g_mpzVar80, ulVar1529);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1531 = iVar1530 < iVar1528;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1527 = (zk_bool)bVar1531;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1527)
            {
                /* CMV_IN(false) */
                zk_bool bVar1532;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1532 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1525 = (zk_bool)bVar1532;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1533;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1534;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1535;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1536;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1534 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1535 = mpz_cmp(g_mpzVar80, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1536 = iVar1535 >= iVar1534;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1533 = (zk_bool)bVar1536;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1533)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1537;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1537 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1525 = (zk_bool)bVar1537;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1538;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1539;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1538);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1538, g_mpzVar80, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1540;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1541;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1542;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1543;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1540 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1541 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1542 = mpz_cmp_ui(mpzVar1538, ulVar1541);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1543 = iVar1542 == iVar1540;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1539 = (zk_bool)bVar1543;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1539)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1544;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1544 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1525 = (zk_bool)bVar1544;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1545;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1545 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1525 = (zk_bool)bVar1545;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1538);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1526 = !bVar1525;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar590 = (zk_bool)bVar1526;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar590)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1546;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1547;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1548;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1546 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1547 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1548 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1548, pccVar1547, iVar1546, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar81, vPublicCommitment_x[22]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1550;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1551;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1552;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1553;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1554;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1555;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1556;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1553 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1554 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1555 = mpz_cmp_ui(g_mpzVar81, ulVar1554);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1556 = iVar1555 < iVar1553;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1552 = (zk_bool)bVar1556;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1552)
            {
                /* CMV_IN(false) */
                zk_bool bVar1557;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1557 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1550 = (zk_bool)bVar1557;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1558;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1559;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1560;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1561;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1559 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1560 = mpz_cmp(g_mpzVar81, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1561 = iVar1560 >= iVar1559;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1558 = (zk_bool)bVar1561;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1558)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1562;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1562 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1550 = (zk_bool)bVar1562;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1563;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1564;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1563);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1563, g_mpzVar81, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1565;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1566;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1567;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1568;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1565 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1566 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1567 = mpz_cmp_ui(mpzVar1563, ulVar1566);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1568 = iVar1567 == iVar1565;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1564 = (zk_bool)bVar1568;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1564)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1569;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1569 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1550 = (zk_bool)bVar1569;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1570;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1570 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1550 = (zk_bool)bVar1570;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1563);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1551 = !bVar1550;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar591 = (zk_bool)bVar1551;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar591)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1571;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1572;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1573;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1571 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1572 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1573 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1573, pccVar1572, iVar1571, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar82, vPublicCommitment_x[23]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1575;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1576;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1577;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1578;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1579;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1580;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1581;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1578 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1579 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1580 = mpz_cmp_ui(g_mpzVar82, ulVar1579);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1581 = iVar1580 < iVar1578;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1577 = (zk_bool)bVar1581;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1577)
            {
                /* CMV_IN(false) */
                zk_bool bVar1582;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1582 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1575 = (zk_bool)bVar1582;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1583;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1584;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1585;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1586;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1584 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1585 = mpz_cmp(g_mpzVar82, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1586 = iVar1585 >= iVar1584;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1583 = (zk_bool)bVar1586;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1583)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1587;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1587 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1575 = (zk_bool)bVar1587;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1588;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1589;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1588);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1588, g_mpzVar82, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1590;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1591;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1592;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1593;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1590 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1591 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1592 = mpz_cmp_ui(mpzVar1588, ulVar1591);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1593 = iVar1592 == iVar1590;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1589 = (zk_bool)bVar1593;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1589)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1594;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1594 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1575 = (zk_bool)bVar1594;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1595;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1595 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1575 = (zk_bool)bVar1595;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1588);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1576 = !bVar1575;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar592 = (zk_bool)bVar1576;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar592)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1596;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1597;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1598;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1596 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1597 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1598 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1598, pccVar1597, iVar1596, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar83, vPublicCommitment_x[24]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1600;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1601;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1602;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1603;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1604;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1605;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1606;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1603 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1604 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1605 = mpz_cmp_ui(g_mpzVar83, ulVar1604);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1606 = iVar1605 < iVar1603;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1602 = (zk_bool)bVar1606;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1602)
            {
                /* CMV_IN(false) */
                zk_bool bVar1607;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1607 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1600 = (zk_bool)bVar1607;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1608;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1609;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1610;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1611;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1609 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1610 = mpz_cmp(g_mpzVar83, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1611 = iVar1610 >= iVar1609;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1608 = (zk_bool)bVar1611;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1608)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1612;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1612 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1600 = (zk_bool)bVar1612;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1613;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1614;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1613);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1613, g_mpzVar83, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1615;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1616;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1617;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1618;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1615 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1616 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1617 = mpz_cmp_ui(mpzVar1613, ulVar1616);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1618 = iVar1617 == iVar1615;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1614 = (zk_bool)bVar1618;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1614)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1619;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1619 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1600 = (zk_bool)bVar1619;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1620;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1620 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1600 = (zk_bool)bVar1620;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1613);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1601 = !bVar1600;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar593 = (zk_bool)bVar1601;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar593)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1621;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1622;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1623;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1621 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1622 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1623 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1623, pccVar1622, iVar1621, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar84, vPublicCommitment_x[25]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1625;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1626;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1627;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1628;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1629;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1630;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1631;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1628 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1629 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1630 = mpz_cmp_ui(g_mpzVar84, ulVar1629);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1631 = iVar1630 < iVar1628;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1627 = (zk_bool)bVar1631;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1627)
            {
                /* CMV_IN(false) */
                zk_bool bVar1632;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1632 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1625 = (zk_bool)bVar1632;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1633;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1634;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1635;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1636;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1634 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1635 = mpz_cmp(g_mpzVar84, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1636 = iVar1635 >= iVar1634;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1633 = (zk_bool)bVar1636;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1633)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1637;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1637 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1625 = (zk_bool)bVar1637;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1638;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1639;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1638);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1638, g_mpzVar84, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1640;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1641;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1642;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1643;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1640 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1641 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1642 = mpz_cmp_ui(mpzVar1638, ulVar1641);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1643 = iVar1642 == iVar1640;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1639 = (zk_bool)bVar1643;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1639)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1644;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1644 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1625 = (zk_bool)bVar1644;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1645;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1645 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1625 = (zk_bool)bVar1645;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1638);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1626 = !bVar1625;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar594 = (zk_bool)bVar1626;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar594)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1646;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1647;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1648;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1646 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1647 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1648 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1648, pccVar1647, iVar1646, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar85, vPublicCommitment_x[26]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1650;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1651;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1652;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1653;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1654;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1655;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1656;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1653 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1654 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1655 = mpz_cmp_ui(g_mpzVar85, ulVar1654);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1656 = iVar1655 < iVar1653;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1652 = (zk_bool)bVar1656;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1652)
            {
                /* CMV_IN(false) */
                zk_bool bVar1657;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1657 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1650 = (zk_bool)bVar1657;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1658;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1659;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1660;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1661;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1659 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1660 = mpz_cmp(g_mpzVar85, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1661 = iVar1660 >= iVar1659;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1658 = (zk_bool)bVar1661;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1658)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1662;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1662 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1650 = (zk_bool)bVar1662;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1663;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1664;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1663);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1663, g_mpzVar85, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1665;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1666;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1667;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1668;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1665 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1666 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1667 = mpz_cmp_ui(mpzVar1663, ulVar1666);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1668 = iVar1667 == iVar1665;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1664 = (zk_bool)bVar1668;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1664)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1669;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1669 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1650 = (zk_bool)bVar1669;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1670;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1670 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1650 = (zk_bool)bVar1670;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1663);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1651 = !bVar1650;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar595 = (zk_bool)bVar1651;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar595)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1671;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1672;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1673;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1671 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1672 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1673 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1673, pccVar1672, iVar1671, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar16, vAux_gi[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar1675;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar1676;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar1677;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar1678;
            /* CMV_IN(1ul) */
            zk_ulong ulVar1679;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar1680;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar1681;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar1678 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar1679 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar1680 = mpz_cmp_ui(g_mpzVar16, ulVar1679);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar1681 = iVar1680 < iVar1678;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar1677 = (zk_bool)bVar1681;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar1677)
            {
                /* CMV_IN(false) */
                zk_bool bVar1682;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1682 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar1675 = (zk_bool)bVar1682;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar1683;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar1684;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar1685;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar1686;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar1684 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar1685 = mpz_cmp(g_mpzVar16, g_mpzVar5);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar1686 = iVar1685 >= iVar1684;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar1683 = (zk_bool)bVar1686;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar1683)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar1687;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1687 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar1675 = (zk_bool)bVar1687;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar1688;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar1689;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar1688);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar1688, g_mpzVar16, g_mpzVar5);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar1690;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar1691;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar1692;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar1693;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar1690 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar1691 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar1692 = mpz_cmp_ui(mpzVar1688, ulVar1691);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar1693 = iVar1692 == iVar1690;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar1689 = (zk_bool)bVar1693;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar1689)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar1694;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1694 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar1675 = (zk_bool)bVar1694;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar1695;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1695 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar1675 = (zk_bool)bVar1695;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar1688);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar1676 = !bVar1675;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar596 = (zk_bool)bVar1676;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar596)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1696;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1697;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar1698;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar1696 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1697 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar1698 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1698, pccVar1697, iVar1696, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* construct [sigma.cpp:40: cplus] */
    /* construct [sigma.cpp:40: c] */
    /* bnz_init(cplus) */
    mpz_init(g_mpzVar380);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar597 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar381, lVar597);
    /* destruct [sigma.cpp:43: CMV_IN(-1l)] */
    /* construct [gsp.cpp:13: l] */
    /* construct [gsp.cpp:22: CMV_IN((unsigned) strtoul(params[4], 0, 10))] */
    uiVar598 = 160;
    /* copy-assign [gsp.cpp:13: l] = [gsp.cpp:22: CMV_IN((unsigned) strtoul(params[4], 0, 10))] */
    g_uiVar382 = uiVar598;
    /* destruct [gsp.cpp:22: CMV_IN((unsigned) strtoul(params[4], 0, 10))] */
    /* construct [gsp.cpp:30: CMV_IN(cp)] */
    mpz_init_set_str(mpzVar599, "1234567", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar1699;
        /* CMV_IN(0ul) */
        zk_ulong ulVar1700;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar1701;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar1702;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar1699 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar1700 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar1701 = mpz_cmp_ui(mpzVar599, ulVar1700);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar1702 = iVar1701 < iVar1699;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar600 = (zk_bool)bVar1702;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar600)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1703;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1704;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar1705;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar1703 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1704 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar1705 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1705, pccVar1704, iVar1703, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar380, mpzVar599);
    /* destruct [gsp.cpp:30: CMV_IN(cp)] */
    mpz_clear(mpzVar599);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar383);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar384);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar385);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar386);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar387);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar388);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar389);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar390);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar391);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar392);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar393);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar394);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar395);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar396);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar397);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar398);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar399);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar400);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar401);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar402);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar403);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar404);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar405);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar406);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar407);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar408);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar409);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar410);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar411);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar412);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar413);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar414);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar415);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar416);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar417);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar418);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar419);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar420);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar421);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar422);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar423);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar424);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar425);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar426);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar427);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar428);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar429);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar430);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar431);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar432);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar433);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar434);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar435);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar436);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar437);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar438);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar439);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar440);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar441);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar442);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar443);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar444);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar445);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar446);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar447);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar448);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar449);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar450);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar451);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar452);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar453);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar454);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar455);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar456);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar457);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar458);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar459);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar460);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar461);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar462);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar463);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar464);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar465);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar466);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar467);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar468);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar469);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar470);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar471);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar472);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar473);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar474);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar475);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar476);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar477);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar478);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar479);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar480);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar481);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar482);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar483);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar484);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar485);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar486);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar487);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar488);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar489);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar490);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar491);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar492);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar493);
    
    return zk_true;
}

/* zk_Prover_p1: sub program */
zk_bool zk_Prover_p1(mpz_t vCommitment[27])
{
    /* bnz_t tight */
    mpz_t mpzVar1706;
    /* bnz_t */
    mpz_t mpzVar1707;
    /* bnz_t */
    mpz_t mpzVar1708;
    /* bnz_t */
    mpz_t mpzVar1709;
    /* bnz_t */
    mpz_t mpzVar1710;
    /* bnz_t */
    mpz_t mpzVar1711;
    /* bnz_t */
    mpz_t mpzVar1712;
    /* bnz_t */
    mpz_t mpzVar1713;
    /* bnz_t */
    mpz_t mpzVar1714;
    /* bnz_t */
    mpz_t mpzVar1715;
    /* bnz_t */
    mpz_t mpzVar1716;
    /* bnz_t */
    mpz_t mpzVar1717;
    /* bnz_t */
    mpz_t mpzVar1718;
    /* bnz_t */
    mpz_t mpzVar1719;
    /* bnz_t */
    mpz_t mpzVar1720;
    /* bnz_t */
    mpz_t mpzVar1721;
    /* bnz_t */
    mpz_t mpzVar1722;
    /* bnz_t */
    mpz_t mpzVar1723;
    /* bnz_t */
    mpz_t mpzVar1724;
    /* bnz_t */
    mpz_t mpzVar1725;
    /* bnz_t */
    mpz_t mpzVar1726;
    /* bnz_t */
    mpz_t mpzVar1727;
    /* bnz_t */
    mpz_t mpzVar1728;
    /* bnz_t */
    mpz_t mpzVar1729;
    /* bnz_t */
    mpz_t mpzVar1730;
    /* bnz_t */
    mpz_t mpzVar1731;
    /* bnz_t */
    mpz_t mpzVar1732;
    /* bnz_t */
    mpz_t mpzVar1733;
    /* bnz_t */
    mpz_t mpzVar1734;
    /* bnz_t */
    mpz_t mpzVar1735;
    /* bnz_t */
    mpz_t mpzVar1736;
    /* bnz_t */
    mpz_t mpzVar1737;
    /* bnz_t */
    mpz_t mpzVar1738;
    /* bnz_t */
    mpz_t mpzVar1739;
    /* bnz_t */
    mpz_t mpzVar1740;
    /* bnz_t */
    mpz_t mpzVar1741;
    /* bnz_t */
    mpz_t mpzVar1742;
    /* bnz_t */
    mpz_t mpzVar1743;
    /* bnz_t */
    mpz_t mpzVar1744;
    /* bnz_t */
    mpz_t mpzVar1745;
    /* bnz_t */
    mpz_t mpzVar1746;
    /* bnz_t */
    mpz_t mpzVar1747;
    /* bnz_t */
    mpz_t mpzVar1748;
    /* CMV_IN(1u) */
    zk_uint uiVar1749;
    /* return of operator [Operator.hpp:352: addition] */
    zk_uint uiVar1750;
    /* ic-copy of [Operator.hpp:33: return of operator [Operator.hpp:352: addition]] */
    zk_ulong ulVar1751;
    /* CMV_IN(1ul) */
    zk_ulong ulVar1752;
    
    /* construct [gsp.cpp:77: bnz_t tight] */
    /* bnz_init(tight) */
    mpz_init(mpzVar1706);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1707);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1708);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1709);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1710);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1711);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1712);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1713);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1714);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1715);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1716);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1717);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1718);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1719);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1720);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1721);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1722);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1723);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1724);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1725);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1726);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1727);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1728);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1729);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1730);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1731);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1732);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1733);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1734);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1735);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1736);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1737);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1738);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1739);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1740);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1741);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1742);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1743);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1744);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1745);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1746);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1747);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar1748);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar452, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar453, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar454, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar455, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar456, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar457, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar458, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar459, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar460, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar461, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar462, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar463, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar464, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar465, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar466, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar467, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar468, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar469, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar470, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar471, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar472, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar473, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar474, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar475, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar476, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar477, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar478, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar479, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar480, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar481, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar482, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar483, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar484, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar485, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar486, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar487, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar488, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar489, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar490, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar491, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar492, g_mpzVar2);
    /* bnz_set(*dst, maxi) */
    mpz_set(g_mpzVar493, g_mpzVar2);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1707, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1708, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1709, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1710, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1711, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1712, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1713, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1714, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1715, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1716, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1717, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1718, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1719, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1720, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1721, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1722, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1723, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1724, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1725, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1726, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1727, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1728, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1729, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1730, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1731, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1732, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1733, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1734, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1735, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1736, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1737, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1738, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1739, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1740, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1741, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1742, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1743, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1744, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1745, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1746, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1747, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(mpzVar1748, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1707, mpzVar1707, g_mpzVar452);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1708, mpzVar1708, g_mpzVar453);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1709, mpzVar1709, g_mpzVar454);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1710, mpzVar1710, g_mpzVar455);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1711, mpzVar1711, g_mpzVar456);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1712, mpzVar1712, g_mpzVar457);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1713, mpzVar1713, g_mpzVar458);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1714, mpzVar1714, g_mpzVar459);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1715, mpzVar1715, g_mpzVar460);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1716, mpzVar1716, g_mpzVar461);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1717, mpzVar1717, g_mpzVar462);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1718, mpzVar1718, g_mpzVar463);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1719, mpzVar1719, g_mpzVar464);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1720, mpzVar1720, g_mpzVar465);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1721, mpzVar1721, g_mpzVar466);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1722, mpzVar1722, g_mpzVar467);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1723, mpzVar1723, g_mpzVar468);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1724, mpzVar1724, g_mpzVar469);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1725, mpzVar1725, g_mpzVar470);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1726, mpzVar1726, g_mpzVar471);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1727, mpzVar1727, g_mpzVar472);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1728, mpzVar1728, g_mpzVar473);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1729, mpzVar1729, g_mpzVar474);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1730, mpzVar1730, g_mpzVar475);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1731, mpzVar1731, g_mpzVar476);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1732, mpzVar1732, g_mpzVar477);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1733, mpzVar1733, g_mpzVar478);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1734, mpzVar1734, g_mpzVar479);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1735, mpzVar1735, g_mpzVar480);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1736, mpzVar1736, g_mpzVar481);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1737, mpzVar1737, g_mpzVar482);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1738, mpzVar1738, g_mpzVar483);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1739, mpzVar1739, g_mpzVar484);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1740, mpzVar1740, g_mpzVar485);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1741, mpzVar1741, g_mpzVar486);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1742, mpzVar1742, g_mpzVar487);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1743, mpzVar1743, g_mpzVar488);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1744, mpzVar1744, g_mpzVar489);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1745, mpzVar1745, g_mpzVar490);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1746, mpzVar1746, g_mpzVar491);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1747, mpzVar1747, g_mpzVar492);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(mpzVar1748, mpzVar1748, g_mpzVar493);
    /* construct [gsp.cpp:84: CMV_IN(1u)] */
    uiVar1749 = 1;
    /* construct [Operator.hpp:33: return of operator [Operator.hpp:352: addition]] */
    /* addition */
    uiVar1750 = g_uiVar382 + uiVar1749;
    /* copy-construct [CopyableVariable.hpp:77: ic-copy of [Operator.hpp:33: return of operator [Operator.hpp:352: addition]]] = [Operator.hpp:33: return of operator [Operator.hpp:352: addition]] */
    ulVar1751 = uiVar1750;
    /* bnz_mul_2exp(tight, cplus, CMV::zk_ulong_t(l + CMV_IN(1u))) */
    mpz_mul_2exp(mpzVar1706, g_mpzVar380, ulVar1751);
    /* destruct [CopyableVariable.hpp:77: ic-copy of [Operator.hpp:33: return of operator [Operator.hpp:352: addition]]] */
    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:352: addition]] */
    /* destruct [gsp.cpp:84: CMV_IN(1u)] */
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar452, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar453, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar454, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar455, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar456, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar457, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar458, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar459, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar460, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar461, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar462, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar463, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar464, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar465, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar466, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar467, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar468, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar469, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar470, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar471, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar472, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar473, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar474, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar475, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar476, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar477, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar478, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar479, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar480, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar481, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar482, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar483, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar484, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar485, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar486, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar487, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar488, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar489, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar490, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar491, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar492, g_mpzVar3, g_mpzVar4);
    /* bnz_mul(minitight, mini, tightness) */
    mpz_mul(g_mpzVar3, g_mpzVar1, mpzVar1706);
    /* bnz_mul(maxitight, maxi, tightness) */
    mpz_mul(g_mpzVar4, g_mpzVar2, mpzVar1706);
    /* Random::irange(*dst, minitight, maxitight) */
    zk_Random_irange(g_mpzVar493, g_mpzVar3, g_mpzVar4);
    /* construct [gsp.cpp:86: CMV_IN(1ul)] */
    ulVar1752 = 1ul;
    /* bnz_tdiv_q_2exp(tight, tight, CMV_IN(1ul)) */
    mpz_tdiv_q_2exp(mpzVar1706, mpzVar1706, ulVar1752);
    /* destruct [gsp.cpp:86: CMV_IN(1ul)] */
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1707, mpzVar1707, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1708, mpzVar1708, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1709, mpzVar1709, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1710, mpzVar1710, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1711, mpzVar1711, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1712, mpzVar1712, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1713, mpzVar1713, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1714, mpzVar1714, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1715, mpzVar1715, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1716, mpzVar1716, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1717, mpzVar1717, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1718, mpzVar1718, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1719, mpzVar1719, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1720, mpzVar1720, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1721, mpzVar1721, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1722, mpzVar1722, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1723, mpzVar1723, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1724, mpzVar1724, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1725, mpzVar1725, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1726, mpzVar1726, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1727, mpzVar1727, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1728, mpzVar1728, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1729, mpzVar1729, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1730, mpzVar1730, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1731, mpzVar1731, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1732, mpzVar1732, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1733, mpzVar1733, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1734, mpzVar1734, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1735, mpzVar1735, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1736, mpzVar1736, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1737, mpzVar1737, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1738, mpzVar1738, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1739, mpzVar1739, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1740, mpzVar1740, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1741, mpzVar1741, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1742, mpzVar1742, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1743, mpzVar1743, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1744, mpzVar1744, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1745, mpzVar1745, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1746, mpzVar1746, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1747, mpzVar1747, mpzVar1706);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(mpzVar1748, mpzVar1748, mpzVar1706);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar452, g_mpzVar452, mpzVar1707);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar453, g_mpzVar453, mpzVar1708);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar454, g_mpzVar454, mpzVar1709);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar455, g_mpzVar455, mpzVar1710);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar456, g_mpzVar456, mpzVar1711);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar457, g_mpzVar457, mpzVar1712);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar458, g_mpzVar458, mpzVar1713);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar459, g_mpzVar459, mpzVar1714);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar460, g_mpzVar460, mpzVar1715);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar461, g_mpzVar461, mpzVar1716);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar462, g_mpzVar462, mpzVar1717);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar463, g_mpzVar463, mpzVar1718);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar464, g_mpzVar464, mpzVar1719);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar465, g_mpzVar465, mpzVar1720);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar466, g_mpzVar466, mpzVar1721);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar467, g_mpzVar467, mpzVar1722);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar468, g_mpzVar468, mpzVar1723);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar469, g_mpzVar469, mpzVar1724);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar470, g_mpzVar470, mpzVar1725);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar471, g_mpzVar471, mpzVar1726);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar472, g_mpzVar472, mpzVar1727);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar473, g_mpzVar473, mpzVar1728);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar474, g_mpzVar474, mpzVar1729);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar475, g_mpzVar475, mpzVar1730);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar476, g_mpzVar476, mpzVar1731);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar477, g_mpzVar477, mpzVar1732);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar478, g_mpzVar478, mpzVar1733);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar479, g_mpzVar479, mpzVar1734);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar480, g_mpzVar480, mpzVar1735);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar481, g_mpzVar481, mpzVar1736);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar482, g_mpzVar482, mpzVar1737);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar483, g_mpzVar483, mpzVar1738);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar484, g_mpzVar484, mpzVar1739);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar485, g_mpzVar485, mpzVar1740);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar486, g_mpzVar486, mpzVar1741);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar487, g_mpzVar487, mpzVar1742);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar488, g_mpzVar488, mpzVar1743);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar489, g_mpzVar489, mpzVar1744);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar490, g_mpzVar490, mpzVar1745);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar491, g_mpzVar491, mpzVar1746);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar492, g_mpzVar492, mpzVar1747);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar493, g_mpzVar493, mpzVar1748);
    /* bnz_clear(tight) */
    mpz_clear(mpzVar1706);
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1707);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1708);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1709);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1710);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1711);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1712);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1713);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1714);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1715);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1716);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1717);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1718);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1719);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1720);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1721);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1722);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1723);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1724);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1725);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1726);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1727);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1728);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1729);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1730);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1731);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1732);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1733);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1734);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1735);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1736);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1737);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1738);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1739);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1740);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1741);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1742);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1743);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1744);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1745);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1746);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1747);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar1748);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* destruct [gsp.cpp:77: bnz_t tight] */
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar131, g_mpzVar14, g_mpzVar452, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar132, g_mpzVar15, g_mpzVar453, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar383, g_mpzVar131, g_mpzVar132);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar383, g_mpzVar383, g_mpzVar5);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar133, g_mpzVar458, g_mpzVar459);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar134, g_mpzVar133, g_mpzVar460);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar135, g_mpzVar134, g_mpzVar461);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar136, g_mpzVar14, g_mpzVar135, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar384, g_mpzVar136, g_mpzVar132);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar384, g_mpzVar384, g_mpzVar5);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar137, g_mpzVar466, g_mpzVar467);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar138, g_mpzVar137, g_mpzVar468);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar139, g_mpzVar138, g_mpzVar469);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar140, g_mpzVar16, g_mpzVar139, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar385, g_mpzVar140, g_mpzVar132);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar385, g_mpzVar385, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar141, g_mpzVar12, g_mpzVar454, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar142, g_mpzVar13, g_mpzVar470, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar386, g_mpzVar141, g_mpzVar142);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar386, g_mpzVar386, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar143, g_mpzVar12, g_mpzVar455, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar144, g_mpzVar13, g_mpzVar471, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar387, g_mpzVar143, g_mpzVar144);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar387, g_mpzVar387, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar145, g_mpzVar12, g_mpzVar456, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar146, g_mpzVar13, g_mpzVar472, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar388, g_mpzVar145, g_mpzVar146);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar388, g_mpzVar388, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar147, g_mpzVar12, g_mpzVar457, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar148, g_mpzVar13, g_mpzVar473, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar389, g_mpzVar147, g_mpzVar148);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar389, g_mpzVar389, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar149, g_mpzVar12, g_mpzVar458, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar150, g_mpzVar13, g_mpzVar474, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar390, g_mpzVar149, g_mpzVar150);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar390, g_mpzVar390, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar151, g_mpzVar12, g_mpzVar459, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar152, g_mpzVar13, g_mpzVar475, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar391, g_mpzVar151, g_mpzVar152);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar391, g_mpzVar391, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar153, g_mpzVar12, g_mpzVar460, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar154, g_mpzVar13, g_mpzVar476, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar392, g_mpzVar153, g_mpzVar154);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar392, g_mpzVar392, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar155, g_mpzVar12, g_mpzVar461, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar156, g_mpzVar13, g_mpzVar477, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar393, g_mpzVar155, g_mpzVar156);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar393, g_mpzVar393, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar157, g_mpzVar12, g_mpzVar462, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar158, g_mpzVar13, g_mpzVar478, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar394, g_mpzVar157, g_mpzVar158);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar394, g_mpzVar394, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar159, g_mpzVar12, g_mpzVar463, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar160, g_mpzVar13, g_mpzVar479, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar395, g_mpzVar159, g_mpzVar160);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar395, g_mpzVar395, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar161, g_mpzVar12, g_mpzVar464, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar162, g_mpzVar13, g_mpzVar480, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar396, g_mpzVar161, g_mpzVar162);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar396, g_mpzVar396, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar163, g_mpzVar12, g_mpzVar465, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar164, g_mpzVar13, g_mpzVar481, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar397, g_mpzVar163, g_mpzVar164);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar397, g_mpzVar397, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar165, g_mpzVar12, g_mpzVar466, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar166, g_mpzVar13, g_mpzVar482, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar398, g_mpzVar165, g_mpzVar166);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar398, g_mpzVar398, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar167, g_mpzVar12, g_mpzVar467, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar168, g_mpzVar13, g_mpzVar483, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar399, g_mpzVar167, g_mpzVar168);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar399, g_mpzVar399, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar169, g_mpzVar12, g_mpzVar468, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar170, g_mpzVar13, g_mpzVar484, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar400, g_mpzVar169, g_mpzVar170);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar400, g_mpzVar400, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar171, g_mpzVar12, g_mpzVar469, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar172, g_mpzVar13, g_mpzVar485, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar401, g_mpzVar171, g_mpzVar172);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar401, g_mpzVar401, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar173, g_mpzVar62, g_mpzVar454, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar174, g_mpzVar13, g_mpzVar486, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar402, g_mpzVar173, g_mpzVar174);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar402, g_mpzVar402, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar175, g_mpzVar63, g_mpzVar455, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar176, g_mpzVar13, g_mpzVar487, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar403, g_mpzVar175, g_mpzVar176);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar403, g_mpzVar403, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar177, g_mpzVar64, g_mpzVar456, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar178, g_mpzVar13, g_mpzVar488, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar404, g_mpzVar177, g_mpzVar178);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar404, g_mpzVar404, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar179, g_mpzVar65, g_mpzVar457, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar180, g_mpzVar13, g_mpzVar489, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar405, g_mpzVar179, g_mpzVar180);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar405, g_mpzVar405, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar181, g_mpzVar70, g_mpzVar462, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar182, g_mpzVar13, g_mpzVar490, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar406, g_mpzVar181, g_mpzVar182);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar406, g_mpzVar406, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar183, g_mpzVar71, g_mpzVar463, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar184, g_mpzVar13, g_mpzVar491, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar407, g_mpzVar183, g_mpzVar184);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar407, g_mpzVar407, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar185, g_mpzVar72, g_mpzVar464, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar186, g_mpzVar13, g_mpzVar492, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar408, g_mpzVar185, g_mpzVar186);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar408, g_mpzVar408, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar187, g_mpzVar73, g_mpzVar465, g_mpzVar5);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar188, g_mpzVar13, g_mpzVar493, g_mpzVar5);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar409, g_mpzVar187, g_mpzVar188);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar409, g_mpzVar409, g_mpzVar5);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[0], g_mpzVar383);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[1], g_mpzVar384);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[2], g_mpzVar385);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[3], g_mpzVar386);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[4], g_mpzVar387);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[5], g_mpzVar388);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[6], g_mpzVar389);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[7], g_mpzVar390);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[8], g_mpzVar391);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[9], g_mpzVar392);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[10], g_mpzVar393);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[11], g_mpzVar394);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[12], g_mpzVar395);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[13], g_mpzVar396);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[14], g_mpzVar397);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[15], g_mpzVar398);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[16], g_mpzVar399);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[17], g_mpzVar400);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[18], g_mpzVar401);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[19], g_mpzVar402);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[20], g_mpzVar403);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[21], g_mpzVar404);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[22], g_mpzVar405);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[23], g_mpzVar406);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[24], g_mpzVar407);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[25], g_mpzVar408);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[26], g_mpzVar409);
    
    return zk_true;
}

/* zk_Prover_p2: sub program */
zk_bool zk_Prover_p2(mpz_t vResponse[42], const mpz_t vChallenge[1])
{
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar1780;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar1781;
    
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar1782;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar1783;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar1784;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar1782 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar1783 = mpz_cmp(vChallenge[0], g_mpzVar380);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar1784 = iVar1783 >= iVar1782;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar1780 = (zk_bool)bVar1784;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar1780)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1786;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1787;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar1788;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar1786 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1787 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar1788 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1788, pccVar1787, iVar1786, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            /* destruct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:74: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] */
    }
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar1789;
        /* CMV_IN(0ul) */
        zk_ulong ulVar1790;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar1791;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar1792;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar1789 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar1790 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar1791 = mpz_cmp_ui(vChallenge[0], ulVar1790);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar1792 = iVar1791 < iVar1789;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar1781 = (zk_bool)bVar1792;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar1781)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar1793;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar1794;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar1795;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar1793 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar1794 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar1795 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar1795, pccVar1794, iVar1793, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar381, vChallenge[0]);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar410, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar411, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar412, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar413, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar414, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar415, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar416, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar417, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar418, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar419, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar420, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar421, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar422, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar423, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar424, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar425, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar426, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar427, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar428, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar429, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar430, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar431, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar432, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar433, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar434, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar435, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar436, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar437, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar438, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar439, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar440, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar441, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar442, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar443, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar444, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar445, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar446, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar447, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar448, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar449, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar450, g_mpzVar1);
    /* bnz_set(*dst, mini) */
    mpz_set(g_mpzVar451, g_mpzVar1);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar410, g_mpzVar17, g_mpzVar410);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar411, g_mpzVar18, g_mpzVar411);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar412, g_mpzVar19, g_mpzVar412);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar413, g_mpzVar20, g_mpzVar413);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar414, g_mpzVar21, g_mpzVar414);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar415, g_mpzVar22, g_mpzVar415);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar416, g_mpzVar23, g_mpzVar416);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar417, g_mpzVar24, g_mpzVar417);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar418, g_mpzVar25, g_mpzVar418);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar419, g_mpzVar26, g_mpzVar419);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar420, g_mpzVar27, g_mpzVar420);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar421, g_mpzVar28, g_mpzVar421);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar422, g_mpzVar29, g_mpzVar422);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar423, g_mpzVar30, g_mpzVar423);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar424, g_mpzVar31, g_mpzVar424);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar425, g_mpzVar32, g_mpzVar425);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar426, g_mpzVar33, g_mpzVar426);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar427, g_mpzVar34, g_mpzVar427);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar428, g_mpzVar35, g_mpzVar428);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar429, g_mpzVar36, g_mpzVar429);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar430, g_mpzVar37, g_mpzVar430);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar431, g_mpzVar38, g_mpzVar431);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar432, g_mpzVar39, g_mpzVar432);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar433, g_mpzVar40, g_mpzVar433);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar434, g_mpzVar41, g_mpzVar434);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar435, g_mpzVar42, g_mpzVar435);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar436, g_mpzVar43, g_mpzVar436);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar437, g_mpzVar44, g_mpzVar437);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar438, g_mpzVar45, g_mpzVar438);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar439, g_mpzVar46, g_mpzVar439);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar440, g_mpzVar47, g_mpzVar440);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar441, g_mpzVar48, g_mpzVar441);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar442, g_mpzVar49, g_mpzVar442);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar443, g_mpzVar50, g_mpzVar443);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar444, g_mpzVar51, g_mpzVar444);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar445, g_mpzVar52, g_mpzVar445);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar446, g_mpzVar53, g_mpzVar446);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar447, g_mpzVar54, g_mpzVar447);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar448, g_mpzVar55, g_mpzVar448);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar449, g_mpzVar56, g_mpzVar449);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar450, g_mpzVar57, g_mpzVar450);
    /* bnz_sub(*dst, *src0, *src1) */
    mpz_sub(g_mpzVar451, g_mpzVar58, g_mpzVar451);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar410, g_mpzVar410, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar411, g_mpzVar411, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar412, g_mpzVar412, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar413, g_mpzVar413, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar414, g_mpzVar414, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar415, g_mpzVar415, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar416, g_mpzVar416, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar417, g_mpzVar417, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar418, g_mpzVar418, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar419, g_mpzVar419, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar420, g_mpzVar420, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar421, g_mpzVar421, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar422, g_mpzVar422, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar423, g_mpzVar423, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar424, g_mpzVar424, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar425, g_mpzVar425, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar426, g_mpzVar426, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar427, g_mpzVar427, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar428, g_mpzVar428, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar429, g_mpzVar429, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar430, g_mpzVar430, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar431, g_mpzVar431, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar432, g_mpzVar432, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar433, g_mpzVar433, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar434, g_mpzVar434, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar435, g_mpzVar435, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar436, g_mpzVar436, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar437, g_mpzVar437, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar438, g_mpzVar438, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar439, g_mpzVar439, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar440, g_mpzVar440, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar441, g_mpzVar441, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar442, g_mpzVar442, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar443, g_mpzVar443, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar444, g_mpzVar444, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar445, g_mpzVar445, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar446, g_mpzVar446, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar447, g_mpzVar447, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar448, g_mpzVar448, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar449, g_mpzVar449, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar450, g_mpzVar450, g_mpzVar381);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar451, g_mpzVar451, g_mpzVar381);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar410, g_mpzVar410, g_mpzVar452);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar411, g_mpzVar411, g_mpzVar453);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar412, g_mpzVar412, g_mpzVar454);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar413, g_mpzVar413, g_mpzVar455);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar414, g_mpzVar414, g_mpzVar456);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar415, g_mpzVar415, g_mpzVar457);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar416, g_mpzVar416, g_mpzVar458);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar417, g_mpzVar417, g_mpzVar459);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar418, g_mpzVar418, g_mpzVar460);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar419, g_mpzVar419, g_mpzVar461);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar420, g_mpzVar420, g_mpzVar462);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar421, g_mpzVar421, g_mpzVar463);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar422, g_mpzVar422, g_mpzVar464);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar423, g_mpzVar423, g_mpzVar465);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar424, g_mpzVar424, g_mpzVar466);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar425, g_mpzVar425, g_mpzVar467);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar426, g_mpzVar426, g_mpzVar468);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar427, g_mpzVar427, g_mpzVar469);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar428, g_mpzVar428, g_mpzVar470);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar429, g_mpzVar429, g_mpzVar471);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar430, g_mpzVar430, g_mpzVar472);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar431, g_mpzVar431, g_mpzVar473);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar432, g_mpzVar432, g_mpzVar474);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar433, g_mpzVar433, g_mpzVar475);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar434, g_mpzVar434, g_mpzVar476);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar435, g_mpzVar435, g_mpzVar477);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar436, g_mpzVar436, g_mpzVar478);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar437, g_mpzVar437, g_mpzVar479);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar438, g_mpzVar438, g_mpzVar480);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar439, g_mpzVar439, g_mpzVar481);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar440, g_mpzVar440, g_mpzVar482);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar441, g_mpzVar441, g_mpzVar483);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar442, g_mpzVar442, g_mpzVar484);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar443, g_mpzVar443, g_mpzVar485);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar444, g_mpzVar444, g_mpzVar486);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar445, g_mpzVar445, g_mpzVar487);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar446, g_mpzVar446, g_mpzVar488);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar447, g_mpzVar447, g_mpzVar489);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar448, g_mpzVar448, g_mpzVar490);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar449, g_mpzVar449, g_mpzVar491);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar450, g_mpzVar450, g_mpzVar492);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar451, g_mpzVar451, g_mpzVar493);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[0], g_mpzVar410);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[1], g_mpzVar411);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[2], g_mpzVar412);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[3], g_mpzVar413);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[4], g_mpzVar414);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[5], g_mpzVar415);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[6], g_mpzVar416);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[7], g_mpzVar417);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[8], g_mpzVar418);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[9], g_mpzVar419);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[10], g_mpzVar420);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[11], g_mpzVar421);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[12], g_mpzVar422);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[13], g_mpzVar423);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[14], g_mpzVar424);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[15], g_mpzVar425);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[16], g_mpzVar426);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[17], g_mpzVar427);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[18], g_mpzVar428);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[19], g_mpzVar429);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[20], g_mpzVar430);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[21], g_mpzVar431);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[22], g_mpzVar432);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[23], g_mpzVar433);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[24], g_mpzVar434);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[25], g_mpzVar435);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[26], g_mpzVar436);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[27], g_mpzVar437);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[28], g_mpzVar438);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[29], g_mpzVar439);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[30], g_mpzVar440);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[31], g_mpzVar441);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[32], g_mpzVar442);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[33], g_mpzVar443);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[34], g_mpzVar444);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[35], g_mpzVar445);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[36], g_mpzVar446);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[37], g_mpzVar447);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[38], g_mpzVar448);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[39], g_mpzVar449);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[40], g_mpzVar450);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[41], g_mpzVar451);
    
    return zk_true;
}

/* zk_Prover_free: sub program */
zk_bool zk_Prover_free()
{
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar383);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar384);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar385);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar386);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar387);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar388);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar389);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar390);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar391);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar392);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar393);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar394);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar395);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar396);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar397);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar398);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar399);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar400);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar401);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar402);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar403);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar404);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar405);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar406);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar407);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar408);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar409);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar410);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar411);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar412);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar413);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar414);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar415);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar416);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar417);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar418);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar419);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar420);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar421);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar422);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar423);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar424);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar425);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar426);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar427);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar428);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar429);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar430);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar431);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar432);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar433);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar434);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar435);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar436);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar437);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar438);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar439);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar440);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar441);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar442);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar443);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar444);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar445);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar446);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar447);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar448);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar449);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar450);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar451);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar452);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar453);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar454);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar455);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar456);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar457);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar458);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar459);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar460);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar461);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar462);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar463);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar464);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar465);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar466);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar467);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar468);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar469);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar470);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar471);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar472);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar473);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar474);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar475);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar476);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar477);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar478);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar479);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar480);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar481);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar482);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar483);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar484);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar485);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar486);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar487);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar488);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar489);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar490);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar491);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar492);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar493);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* destruct [gsp.cpp:13: l] */
    /* bnz_clear(cplus) */
    mpz_clear(g_mpzVar380);
    /* bnz_clear(c) */
    mpz_clear(g_mpzVar381);
    /* destruct [sigma.cpp:40: c] */
    /* destruct [sigma.cpp:40: cplus] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar189);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar190);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar191);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar192);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar193);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar194);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar195);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar196);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar197);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar198);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar199);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar200);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar201);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar202);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar203);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar204);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar205);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar206);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar207);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar208);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar209);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar210);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar211);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar212);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar213);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar214);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar215);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar216);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar217);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar218);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar219);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar220);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar221);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar222);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar223);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar224);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar225);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar226);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar227);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar228);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar229);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar230);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar231);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar232);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar233);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar234);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar235);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar236);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar237);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar238);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar239);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar240);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar241);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar242);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar243);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar244);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar245);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar246);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar247);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar248);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar249);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar250);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar251);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar252);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar253);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar254);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar255);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar256);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar257);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar258);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar259);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar260);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar261);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar262);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar263);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar264);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar265);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar266);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar267);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar268);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar269);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar270);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar271);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar272);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar273);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar274);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar275);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar276);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar277);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar278);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar279);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar280);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar281);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar282);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar283);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar284);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar285);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar286);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar287);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar288);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar289);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar290);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar291);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar292);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar293);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar294);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar295);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar296);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar297);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar298);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar299);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar300);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar301);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar302);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar303);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar304);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar305);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar306);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar307);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar308);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar309);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar310);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar311);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar312);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar313);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar314);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar315);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar316);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar317);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar318);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar319);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar320);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar321);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar322);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar323);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar324);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar325);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar326);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar327);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar328);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar329);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar330);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar331);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar332);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar333);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar334);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar335);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar336);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar337);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar338);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar339);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar340);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar341);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar342);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar343);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar344);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar345);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar346);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar347);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar348);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar349);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar350);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar351);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar352);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar353);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar354);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar355);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar356);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar357);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar358);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar359);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar360);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar361);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar362);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar363);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar364);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar365);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar366);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar367);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar368);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar369);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar370);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar371);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar372);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar373);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar374);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar375);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar376);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar377);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar378);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar379);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar10);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar11);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar12);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar13);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar14);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar15);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar16);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar17);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar18);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar19);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar20);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar21);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar22);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar23);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar24);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar25);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar26);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar27);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar28);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar29);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar30);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar31);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar32);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar33);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar34);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar35);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar36);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar37);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar38);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar39);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar40);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar41);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar42);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar43);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar44);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar45);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar46);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar47);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar48);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar49);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar50);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar51);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar52);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar53);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar54);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar55);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar56);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar57);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar58);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar59);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar60);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar61);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar62);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar63);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar64);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar65);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar66);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar67);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar68);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar69);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar70);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar71);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar72);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar73);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar74);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar75);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar76);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar77);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar78);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar79);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar80);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar81);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar82);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar83);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar84);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar85);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar86);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar87);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar88);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar89);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar90);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar91);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar92);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar93);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar94);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar95);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar96);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar97);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar98);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar99);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar100);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar101);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar102);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar103);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar104);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar105);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar106);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar107);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar108);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar109);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar110);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar111);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar112);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar113);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar114);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar115);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar116);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar117);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar118);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar119);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar120);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar121);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar122);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar123);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar124);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar125);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar126);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar127);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar128);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar129);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar130);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar131);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar132);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar133);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar134);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar135);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar136);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar137);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar138);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar139);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar140);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar141);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar142);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar143);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar144);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar145);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar146);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar147);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar148);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar149);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar150);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar151);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar152);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar153);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar154);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar155);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar156);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar157);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar158);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar159);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar160);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar161);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar162);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar163);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar164);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar165);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar166);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar167);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar168);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar169);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar170);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar171);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar172);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar173);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar174);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar175);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar176);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar177);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar178);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar179);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar180);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar181);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar182);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar183);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar184);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar185);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar186);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar187);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar188);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(mini) */
    mpz_clear(g_mpzVar1);
    /* bnz_clear(maxi) */
    mpz_clear(g_mpzVar2);
    /* bnz_clear(minitight) */
    mpz_clear(g_mpzVar3);
    /* bnz_clear(maxitight) */
    mpz_clear(g_mpzVar4);
    /* destruct [z.cpp:27: maxitight] */
    /* destruct [z.cpp:27: minitight] */
    /* destruct [z.cpp:27: maxi] */
    /* destruct [z.cpp:27: mini] */
    /* bnz_clear(n) */
    mpz_clear(g_mpzVar5);
    /* destruct [z_mul_n.cpp:32: n] */
    /* bnz_clear(mini) */
    mpz_clear(g_mpzVar6);
    /* bnz_clear(maxi) */
    mpz_clear(g_mpzVar7);
    /* bnz_clear(minitight) */
    mpz_clear(g_mpzVar8);
    /* bnz_clear(maxitight) */
    mpz_clear(g_mpzVar9);
    /* destruct [z.cpp:27: maxitight] */
    /* destruct [z.cpp:27: minitight] */
    /* destruct [z.cpp:27: maxi] */
    /* destruct [z.cpp:27: mini] */
    
    return zk_true;
}

/* end c-source-code of program "prover" */
