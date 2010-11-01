/* begin c-source-code of program "verifier" */
#include "zk_verifier.h"

/* n */
static mpz_t g_mpzVar1;
/* n */
static mpz_t g_mpzVar2;
/* bnz_t */
static mpz_t g_mpzVar3;
/* bnz_t */
static mpz_t g_mpzVar4;
/* bnz_t */
static mpz_t g_mpzVar5;
/* bnz_t */
static mpz_t g_mpzVar6;
/* bnz_t */
static mpz_t g_mpzVar7;
/* bnz_t */
static mpz_t g_mpzVar8;
/* bnz_t */
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
/* cplus */
static mpz_t g_mpzVar19;
/* c */
static mpz_t g_mpzVar20;
/* cplus */
static mpz_t g_mpzVar21;
/* c */
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
/* cplus */
static mpz_t g_mpzVar28;
/* c */
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
/* cplus */
static mpz_t g_mpzVar35;
/* c */
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

/* zk_Verifier_init: sub program */
zk_bool zk_Verifier_init(const mpz_t vPublicCommitment_x0[1], const mpz_t vPublicCommitment_x1[1], const mpz_t vPublicCommitment_x2[1])
{
    /* CMV_IN(tmpN) */
    mpz_t mpzVar42;
    /* CMV_IN(tmpN) */
    mpz_t mpzVar43;
    /* zk_pcchar_t */
    zk_pcchar pccVar44;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar45;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar46;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar47;
    /* zk_pcchar_t */
    zk_pcchar pccVar48;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar49;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar50;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar51;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar52;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar53;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar54;
    /* CMV_IN(-1l) */
    zk_long lVar55;
    /* bnz_t min */
    mpz_t mpzVar56;
    /* bnz_t cp */
    mpz_t mpzVar57;
    /* CMV_IN(-1l) */
    zk_long lVar58;
    /* CMV_IN(cp) */
    mpz_t mpzVar59;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar60;
    /* CMV_IN(-1l) */
    zk_long lVar61;
    /* CMV_IN(cp) */
    mpz_t mpzVar62;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar63;
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    zk_bool bVar64;
    /* CMV_IN(-1l) */
    zk_long lVar65;
    /* CMV_IN(cp) */
    mpz_t mpzVar66;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar67;
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    zk_bool bVar68;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar69;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar70;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar71;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar72;
    
    /* construct [z_add_n.cpp:28: n] */
    /* construct [z_add_n.cpp:41: CMV_IN(tmpN)] */
    mpz_init_set_str(mpzVar42, "509", 10);
    /* bnz_init_set(n, CMV_IN(tmpN)) */
    mpz_init_set(g_mpzVar1, mpzVar42);
    /* destruct [z_add_n.cpp:41: CMV_IN(tmpN)] */
    mpz_clear(mpzVar42);
    /* construct [z_mul_n.cpp:32: n] */
    /* construct [z_mul_n.cpp:53: CMV_IN(tmpN)] */
    mpz_init_set_str(mpzVar43, "1019", 10);
    /* bnz_init_set(n, CMV_IN(tmpN)) */
    mpz_init_set(g_mpzVar2, mpzVar43);
    /* destruct [z_mul_n.cpp:53: CMV_IN(tmpN)] */
    mpz_clear(mpzVar43);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar3);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar4);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar5);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar6);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar7);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar8);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar9);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar10);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar11);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar12);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar45 = "452";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar44 = pccVar45;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar73;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar74;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar73 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar74 = mpz_set_str(g_mpzVar12, pccVar44, iVar73);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar46 = (zk_bool)iVar74;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar46)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar75;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar76;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar77;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar75 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar76 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar77 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar77, pccVar76, iVar75, __FILE__, __LINE__);
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
        zk_bool bVar78;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar79;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar80;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar81;
            /* CMV_IN(1ul) */
            zk_ulong ulVar82;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar83;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar84;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar81 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar82 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar83 = mpz_cmp_ui(g_mpzVar12, ulVar82);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar84 = iVar83 < iVar81;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar80 = (zk_bool)bVar84;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar80)
            {
                /* CMV_IN(false) */
                zk_bool bVar85;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar85 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar78 = (zk_bool)bVar85;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar86;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar87;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar88;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar89;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar87 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar88 = mpz_cmp(g_mpzVar12, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar89 = iVar88 >= iVar87;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar86 = (zk_bool)bVar89;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar86)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar90;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar90 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar78 = (zk_bool)bVar90;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar91;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar92;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar91);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar91, g_mpzVar12, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar93;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar94;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar95;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar96;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar93 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar94 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar95 = mpz_cmp_ui(mpzVar91, ulVar94);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar96 = iVar95 == iVar93;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar92 = (zk_bool)bVar96;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar92)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar97;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar97 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar78 = (zk_bool)bVar97;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar98;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar98 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar78 = (zk_bool)bVar98;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar91);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar79 = !bVar78;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar47 = (zk_bool)bVar79;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar47)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar99;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar100;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar101;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar99 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar100 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar101 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar101, pccVar100, iVar99, __FILE__, __LINE__);
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
    pccVar49 = "311";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar48 = pccVar49;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar102;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar103;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar102 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar103 = mpz_set_str(g_mpzVar13, pccVar48, iVar102);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar50 = (zk_bool)iVar103;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar50)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar104;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar105;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar106;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar104 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar105 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar106 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar106, pccVar105, iVar104, __FILE__, __LINE__);
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
        zk_bool bVar107;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar108;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar109;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar110;
            /* CMV_IN(1ul) */
            zk_ulong ulVar111;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar112;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar113;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar110 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar111 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar112 = mpz_cmp_ui(g_mpzVar13, ulVar111);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar113 = iVar112 < iVar110;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar109 = (zk_bool)bVar113;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar109)
            {
                /* CMV_IN(false) */
                zk_bool bVar114;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar114 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar107 = (zk_bool)bVar114;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar115;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar116;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar117;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar118;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar116 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar117 = mpz_cmp(g_mpzVar13, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar118 = iVar117 >= iVar116;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar115 = (zk_bool)bVar118;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar115)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar119;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar119 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar107 = (zk_bool)bVar119;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar120;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar121;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar120);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar120, g_mpzVar13, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar122;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar123;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar124;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar125;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar122 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar123 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar124 = mpz_cmp_ui(mpzVar120, ulVar123);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar125 = iVar124 == iVar122;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar121 = (zk_bool)bVar125;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar121)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar126;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar126 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar107 = (zk_bool)bVar126;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar127;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar127 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar107 = (zk_bool)bVar127;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar120);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar108 = !bVar107;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar51 = (zk_bool)bVar108;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar51)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar128;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar129;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar130;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar128 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar129 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar130 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar130, pccVar129, iVar128, __FILE__, __LINE__);
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
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar15);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar16);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar17);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar18);
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar9, vPublicCommitment_x0[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar132;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar133;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar134;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar135;
            /* CMV_IN(1ul) */
            zk_ulong ulVar136;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar137;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar138;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar135 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar136 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar137 = mpz_cmp_ui(g_mpzVar9, ulVar136);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar138 = iVar137 < iVar135;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar134 = (zk_bool)bVar138;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar134)
            {
                /* CMV_IN(false) */
                zk_bool bVar139;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar139 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar132 = (zk_bool)bVar139;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar140;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar141;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar142;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar143;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar141 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar142 = mpz_cmp(g_mpzVar9, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar143 = iVar142 >= iVar141;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar140 = (zk_bool)bVar143;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar140)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar144;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar144 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar132 = (zk_bool)bVar144;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar145;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar146;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar145);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar145, g_mpzVar9, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar147;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar148;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar149;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar150;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar147 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar148 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar149 = mpz_cmp_ui(mpzVar145, ulVar148);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar150 = iVar149 == iVar147;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar146 = (zk_bool)bVar150;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar146)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar151;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar151 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar132 = (zk_bool)bVar151;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar152;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar152 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar132 = (zk_bool)bVar152;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar145);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar133 = !bVar132;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar52 = (zk_bool)bVar133;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar52)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar153;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar154;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar155;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar153 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar154 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar155 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar155, pccVar154, iVar153, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar10, vPublicCommitment_x1[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar157;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar158;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar159;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar160;
            /* CMV_IN(1ul) */
            zk_ulong ulVar161;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar162;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar163;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar160 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar161 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar162 = mpz_cmp_ui(g_mpzVar10, ulVar161);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar163 = iVar162 < iVar160;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar159 = (zk_bool)bVar163;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar159)
            {
                /* CMV_IN(false) */
                zk_bool bVar164;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar164 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar157 = (zk_bool)bVar164;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar165;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar166;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar167;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar168;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar166 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar167 = mpz_cmp(g_mpzVar10, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar168 = iVar167 >= iVar166;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar165 = (zk_bool)bVar168;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar165)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar169;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar169 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar157 = (zk_bool)bVar169;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar170;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar171;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar170);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar170, g_mpzVar10, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar172;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar173;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar174;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar175;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar172 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar173 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar174 = mpz_cmp_ui(mpzVar170, ulVar173);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar175 = iVar174 == iVar172;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar171 = (zk_bool)bVar175;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar171)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar176;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar176 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar157 = (zk_bool)bVar176;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar177;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar177 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar157 = (zk_bool)bVar177;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar170);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar158 = !bVar157;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar53 = (zk_bool)bVar158;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar53)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar178;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar179;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar180;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar178 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar179 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar180 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar180, pccVar179, iVar178, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar11, vPublicCommitment_x2[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar182;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar183;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar184;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar185;
            /* CMV_IN(1ul) */
            zk_ulong ulVar186;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar187;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar188;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar185 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar186 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar187 = mpz_cmp_ui(g_mpzVar11, ulVar186);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar188 = iVar187 < iVar185;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar184 = (zk_bool)bVar188;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar184)
            {
                /* CMV_IN(false) */
                zk_bool bVar189;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar189 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar182 = (zk_bool)bVar189;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar190;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar191;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar192;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar193;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar191 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar192 = mpz_cmp(g_mpzVar11, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar193 = iVar192 >= iVar191;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar190 = (zk_bool)bVar193;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar190)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar194;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar194 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar182 = (zk_bool)bVar194;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar195;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar196;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar195);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar195, g_mpzVar11, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar197;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar198;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar199;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar200;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar197 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar198 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar199 = mpz_cmp_ui(mpzVar195, ulVar198);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar200 = iVar199 == iVar197;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar196 = (zk_bool)bVar200;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar196)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar201;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar201 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar182 = (zk_bool)bVar201;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar202;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar202 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar182 = (zk_bool)bVar202;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar195);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar183 = !bVar182;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar54 = (zk_bool)bVar183;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar54)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar203;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar204;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar205;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar203 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar204 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar205 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar205, pccVar204, iVar203, __FILE__, __LINE__);
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
    mpz_init(g_mpzVar19);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar55 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar20, lVar55);
    /* destruct [sigma.cpp:43: CMV_IN(-1l)] */
    /* construct [and.cpp:40: bnz_t min] */
    /* construct [and.cpp:41: bnz_t cp] */
    /* bnz_init(min) */
    mpz_init(mpzVar56);
    /* bnz_init(cp) */
    mpz_init(mpzVar57);
    /* construct [sigma.cpp:40: cplus] */
    /* construct [sigma.cpp:40: c] */
    /* bnz_init(cplus) */
    mpz_init(g_mpzVar21);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar58 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar22, lVar58);
    /* destruct [sigma.cpp:43: CMV_IN(-1l)] */
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
    /* construct [phi.cpp:22: CMV_IN(cp)] */
    mpz_init_set_str(mpzVar59, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar206;
        /* CMV_IN(0ul) */
        zk_ulong ulVar207;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar208;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar209;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar206 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar207 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar208 = mpz_cmp_ui(mpzVar59, ulVar207);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar209 = iVar208 < iVar206;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar60 = (zk_bool)bVar209;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar60)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar210;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar211;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar212;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar210 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar211 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar212 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar212, pccVar211, iVar210, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar21, mpzVar59);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar59);
    /* bnz_set(cplus_, cplus) */
    mpz_set(mpzVar57, g_mpzVar21);
    /* bnz_set(min, cp) */
    mpz_set(mpzVar56, mpzVar57);
    /* construct [sigma.cpp:40: cplus] */
    /* construct [sigma.cpp:40: c] */
    /* bnz_init(cplus) */
    mpz_init(g_mpzVar28);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar61 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar29, lVar61);
    /* destruct [sigma.cpp:43: CMV_IN(-1l)] */
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
    /* construct [phi.cpp:22: CMV_IN(cp)] */
    mpz_init_set_str(mpzVar62, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar213;
        /* CMV_IN(0ul) */
        zk_ulong ulVar214;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar215;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar216;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar213 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar214 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar215 = mpz_cmp_ui(mpzVar62, ulVar214);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar216 = iVar215 < iVar213;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar63 = (zk_bool)bVar216;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar63)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar217;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar218;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar219;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar217 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar218 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar219 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar219, pccVar218, iVar217, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar28, mpzVar62);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar62);
    /* bnz_set(cplus_, cplus) */
    mpz_set(mpzVar57, g_mpzVar28);
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar220;
        /* return of function [and.cpp:54: bnz_cmp(cp, min)] */
        zk_int iVar221;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar222;
        
        /* construct [and.cpp:54: CMV_IN(0)] */
        iVar220 = 0;
        /* construct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* bnz_cmp(cp, min) */
        iVar221 = mpz_cmp(mpzVar57, mpzVar56);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar222 = iVar221 < iVar220;
        /* copy-construct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar64 = (zk_bool)bVar222;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* destruct [and.cpp:54: CMV_IN(0)] */
        if (bVar64)
        {
            /* bnz_set(min, cp) */
            mpz_set(mpzVar56, mpzVar57);
        }
        /* destruct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] */
    }
    /* construct [sigma.cpp:40: cplus] */
    /* construct [sigma.cpp:40: c] */
    /* bnz_init(cplus) */
    mpz_init(g_mpzVar35);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar65 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar36, lVar65);
    /* destruct [sigma.cpp:43: CMV_IN(-1l)] */
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
    /* construct [phi.cpp:22: CMV_IN(cp)] */
    mpz_init_set_str(mpzVar66, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar223;
        /* CMV_IN(0ul) */
        zk_ulong ulVar224;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar225;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar226;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar223 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar224 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar225 = mpz_cmp_ui(mpzVar66, ulVar224);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar226 = iVar225 < iVar223;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar67 = (zk_bool)bVar226;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar67)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar227;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar228;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar229;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar227 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar228 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar229 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar229, pccVar228, iVar227, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar35, mpzVar66);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar66);
    /* bnz_set(cplus_, cplus) */
    mpz_set(mpzVar57, g_mpzVar35);
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar230;
        /* return of function [and.cpp:54: bnz_cmp(cp, min)] */
        zk_int iVar231;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar232;
        
        /* construct [and.cpp:54: CMV_IN(0)] */
        iVar230 = 0;
        /* construct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* bnz_cmp(cp, min) */
        iVar231 = mpz_cmp(mpzVar57, mpzVar56);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar232 = iVar231 < iVar230;
        /* copy-construct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar68 = (zk_bool)bVar232;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* destruct [and.cpp:54: CMV_IN(0)] */
        if (bVar68)
        {
            /* bnz_set(min, cp) */
            mpz_set(mpzVar56, mpzVar57);
        }
        /* destruct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] */
    }
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar233;
        /* CMV_IN(0ul) */
        zk_ulong ulVar234;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar235;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar236;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar233 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar234 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar235 = mpz_cmp_ui(mpzVar56, ulVar234);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar236 = iVar235 < iVar233;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar69 = (zk_bool)bVar236;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar69)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar237;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar238;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar239;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar237 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar238 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar239 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar239, pccVar238, iVar237, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar19, mpzVar56);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar240;
        /* CMV_IN(0ul) */
        zk_ulong ulVar241;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar242;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar243;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar240 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar241 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar242 = mpz_cmp_ui(mpzVar56, ulVar241);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar243 = iVar242 < iVar240;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar70 = (zk_bool)bVar243;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar70)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar244;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar245;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar246;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar244 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar245 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar246 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar246, pccVar245, iVar244, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar21, mpzVar56);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar247;
        /* CMV_IN(0ul) */
        zk_ulong ulVar248;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar249;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar250;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar247 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar248 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar249 = mpz_cmp_ui(mpzVar56, ulVar248);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar250 = iVar249 < iVar247;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar71 = (zk_bool)bVar250;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar71)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar251;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar252;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar253;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar251 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar252 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar253 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar253, pccVar252, iVar251, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar28, mpzVar56);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar254;
        /* CMV_IN(0ul) */
        zk_ulong ulVar255;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar256;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar257;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar254 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar255 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar256 = mpz_cmp_ui(mpzVar56, ulVar255);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar257 = iVar256 < iVar254;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar72 = (zk_bool)bVar257;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar72)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar258;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar259;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar260;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar258 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar259 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar260 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar260, pccVar259, iVar258, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar35, mpzVar56);
    /* bnz_clear(min) */
    mpz_clear(mpzVar56);
    /* bnz_clear(cp) */
    mpz_clear(mpzVar57);
    /* destruct [and.cpp:41: bnz_t cp] */
    /* destruct [and.cpp:40: bnz_t min] */
    
    return zk_true;
}

/* zk_Verifier_c: sub program */
zk_bool zk_Verifier_c(mpz_t vChallenge[1], const mpz_t vCommitment[3])
{
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar261;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar262;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar263;
    /* bnz_t c_ */
    mpz_t mpzVar264;
    /* CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul)))) */
    zk_bool bVar265;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar266;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar267;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar268;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar269;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar270;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar271;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar272;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar273;
    /* CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar274;
    
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar23, vCommitment[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar276;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar277;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar278;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar279;
            /* CMV_IN(1ul) */
            zk_ulong ulVar280;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar281;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar282;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar279 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar280 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar281 = mpz_cmp_ui(g_mpzVar23, ulVar280);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar282 = iVar281 < iVar279;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar278 = (zk_bool)bVar282;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar278)
            {
                /* CMV_IN(false) */
                zk_bool bVar283;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar283 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar276 = (zk_bool)bVar283;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar284;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar285;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar286;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar287;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar285 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar286 = mpz_cmp(g_mpzVar23, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar287 = iVar286 >= iVar285;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar284 = (zk_bool)bVar287;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar284)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar288;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar288 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar276 = (zk_bool)bVar288;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar289;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar290;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar289);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar289, g_mpzVar23, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar291;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar292;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar293;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar294;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar291 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar292 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar293 = mpz_cmp_ui(mpzVar289, ulVar292);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar294 = iVar293 == iVar291;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar290 = (zk_bool)bVar294;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar290)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar295;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar295 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar276 = (zk_bool)bVar295;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar296;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar296 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar276 = (zk_bool)bVar296;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar289);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar277 = !bVar276;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar261 = (zk_bool)bVar277;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar261)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar297;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar298;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar299;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar297 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar298 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar299 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar299, pccVar298, iVar297, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar30, vCommitment[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar301;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar302;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar303;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar304;
            /* CMV_IN(1ul) */
            zk_ulong ulVar305;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar306;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar307;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar304 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar305 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar306 = mpz_cmp_ui(g_mpzVar30, ulVar305);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar307 = iVar306 < iVar304;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar303 = (zk_bool)bVar307;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar303)
            {
                /* CMV_IN(false) */
                zk_bool bVar308;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar308 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar301 = (zk_bool)bVar308;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar309;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar310;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar311;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar312;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar310 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar311 = mpz_cmp(g_mpzVar30, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar312 = iVar311 >= iVar310;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar309 = (zk_bool)bVar312;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar309)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar313;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar313 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar301 = (zk_bool)bVar313;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar314;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar315;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar314);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar314, g_mpzVar30, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar316;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar317;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar318;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar319;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar316 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar317 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar318 = mpz_cmp_ui(mpzVar314, ulVar317);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar319 = iVar318 == iVar316;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar315 = (zk_bool)bVar319;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar315)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar320;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar320 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar301 = (zk_bool)bVar320;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar321;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar321 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar301 = (zk_bool)bVar321;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar314);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar302 = !bVar301;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar262 = (zk_bool)bVar302;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar262)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar322;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar323;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar324;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar322 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar323 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar324 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar324, pccVar323, iVar322, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar37, vCommitment[2]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar326;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar327;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar328;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar329;
            /* CMV_IN(1ul) */
            zk_ulong ulVar330;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar331;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar332;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar329 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar330 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar331 = mpz_cmp_ui(g_mpzVar37, ulVar330);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar332 = iVar331 < iVar329;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar328 = (zk_bool)bVar332;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar328)
            {
                /* CMV_IN(false) */
                zk_bool bVar333;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar333 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar326 = (zk_bool)bVar333;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar334;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar335;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar336;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar337;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar335 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar336 = mpz_cmp(g_mpzVar37, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar337 = iVar336 >= iVar335;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar334 = (zk_bool)bVar337;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar334)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar338;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar338 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar326 = (zk_bool)bVar338;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar339;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar340;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar339);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar339, g_mpzVar37, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar341;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar342;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar343;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar344;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar341 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar342 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar343 = mpz_cmp_ui(mpzVar339, ulVar342);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar344 = iVar343 == iVar341;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar340 = (zk_bool)bVar344;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar340)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar345;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar345 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar326 = (zk_bool)bVar345;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar346;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar346 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar326 = (zk_bool)bVar346;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar339);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar327 = !bVar326;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar263 = (zk_bool)bVar327;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar263)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar347;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar348;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar349;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar347 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar348 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar349 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar349, pccVar348, iVar347, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* construct [sigma.cpp:59: bnz_t c_] */
    /* CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul)))) */
    {
        /* CMV_IN(0ul) */
        zk_ulong ulVar350;
        /* return of function [sigma.cpp:60: bnz_cmp_ui(cplus, CMV_IN(0ul))] */
        zk_int iVar351;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar352;
        
        /* construct [sigma.cpp:60: CMV_IN(0ul)] */
        ulVar350 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:60: bnz_cmp_ui(cplus, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus, CMV_IN(0ul)) */
        iVar351 = mpz_cmp_ui(g_mpzVar19, ulVar350);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar352 = !iVar351;
        /* copy-construct [sigma.cpp:60: CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul))))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar265 = (zk_bool)bVar352;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:60: bnz_cmp_ui(cplus, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:60: CMV_IN(0ul)] */
        if (bVar265)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar353;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar354;
            /* CMV_IN((zk_pcchar_t)("cplus not set")) */
            zk_pcchar pccVar355;
            
            /* construct [sigma.cpp:61: CMV_IN(__LINE__)] */
            iVar353 = 61;
            /* construct [sigma.cpp:61: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar354 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:61: CMV_IN((zk_pcchar_t)("cplus not set"))] */
            pccVar355 = "cplus not set";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus not set"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus not set\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 61))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar355, pccVar354, iVar353, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:61: CMV_IN((zk_pcchar_t)("cplus not set"))] */
            /* destruct [sigma.cpp:61: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:61: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:60: CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul))))] */
    }
    /* bnz_init(c_) */
    mpz_init(mpzVar264);
    /* Random::range0(c_, cplus) */
    zk_Random_range0(mpzVar264, g_mpzVar19);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar356;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar357;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar358;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar356 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar357 = mpz_cmp(mpzVar264, g_mpzVar19);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar358 = iVar357 >= iVar356;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar266 = (zk_bool)bVar358;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar266)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar359;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar360;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar361;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar359 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar360 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar361 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar361, pccVar360, iVar359, __FILE__, __LINE__);
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
        zk_int iVar362;
        /* CMV_IN(0ul) */
        zk_ulong ulVar363;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar364;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar365;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar362 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar363 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar364 = mpz_cmp_ui(mpzVar264, ulVar363);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar365 = iVar364 < iVar362;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar267 = (zk_bool)bVar365;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar267)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar366;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar367;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar368;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar366 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar367 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar368 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar368, pccVar367, iVar366, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar20, mpzVar264);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar369;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar370;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar371;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar369 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar370 = mpz_cmp(mpzVar264, g_mpzVar21);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar371 = iVar370 >= iVar369;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar268 = (zk_bool)bVar371;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar268)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar372;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar373;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar374;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar372 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar373 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar374 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar374, pccVar373, iVar372, __FILE__, __LINE__);
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
        zk_int iVar375;
        /* CMV_IN(0ul) */
        zk_ulong ulVar376;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar377;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar378;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar375 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar376 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar377 = mpz_cmp_ui(mpzVar264, ulVar376);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar378 = iVar377 < iVar375;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar269 = (zk_bool)bVar378;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar269)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar379;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar380;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar381;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar379 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar380 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar381 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar381, pccVar380, iVar379, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar22, mpzVar264);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar382;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar383;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar384;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar382 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar383 = mpz_cmp(mpzVar264, g_mpzVar28);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar384 = iVar383 >= iVar382;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar270 = (zk_bool)bVar384;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar270)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar385;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar386;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar387;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar385 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar386 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar387 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar387, pccVar386, iVar385, __FILE__, __LINE__);
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
        zk_int iVar388;
        /* CMV_IN(0ul) */
        zk_ulong ulVar389;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar390;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar391;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar388 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar389 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar390 = mpz_cmp_ui(mpzVar264, ulVar389);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar391 = iVar390 < iVar388;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar271 = (zk_bool)bVar391;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar271)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar392;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar393;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar394;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar392 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar393 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar394 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar394, pccVar393, iVar392, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar29, mpzVar264);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar395;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar396;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar397;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar395 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar396 = mpz_cmp(mpzVar264, g_mpzVar35);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar397 = iVar396 >= iVar395;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar272 = (zk_bool)bVar397;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar272)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar398;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar399;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar400;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar398 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar399 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar400 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar400, pccVar399, iVar398, __FILE__, __LINE__);
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
        zk_int iVar401;
        /* CMV_IN(0ul) */
        zk_ulong ulVar402;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar403;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar404;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar401 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar402 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar403 = mpz_cmp_ui(mpzVar264, ulVar402);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar404 = iVar403 < iVar401;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar273 = (zk_bool)bVar404;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar273)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar405;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar406;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar407;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar405 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar406 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar407 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar407, pccVar406, iVar405, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar36, mpzVar264);
    /* bnz_clear(c_) */
    mpz_clear(mpzVar264);
    /* destruct [sigma.cpp:59: bnz_t c_] */
    /* CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar408;
        /* CMV_IN(0ul) */
        zk_ulong ulVar409;
        /* return of function [sigma.cpp:98: bnz_cmp_ui(c, CMV_IN(0ul))] */
        zk_int iVar410;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar411;
        
        /* construct [sigma.cpp:98: CMV_IN(0)] */
        iVar408 = 0;
        /* construct [sigma.cpp:98: CMV_IN(0ul)] */
        ulVar409 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:98: bnz_cmp_ui(c, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c, CMV_IN(0ul)) */
        iVar410 = mpz_cmp_ui(g_mpzVar20, ulVar409);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar411 = iVar410 < iVar408;
        /* copy-construct [sigma.cpp:98: CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar274 = (zk_bool)bVar411;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:98: bnz_cmp_ui(c, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:98: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:98: CMV_IN(0)] */
        if (bVar274)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar412;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar413;
            /* CMV_IN((zk_pcchar_t)("challenge not set")) */
            zk_pcchar pccVar414;
            
            /* construct [sigma.cpp:99: CMV_IN(__LINE__)] */
            iVar412 = 99;
            /* construct [sigma.cpp:99: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar413 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:99: CMV_IN((zk_pcchar_t)("challenge not set"))] */
            pccVar414 = "challenge not set";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("challenge not set"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"challenge not set\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 99))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar414, pccVar413, iVar412, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:99: CMV_IN((zk_pcchar_t)("challenge not set"))] */
            /* destruct [sigma.cpp:99: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:99: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:98: CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c_, c) */
    mpz_set(vChallenge[0], g_mpzVar20);
    
    return zk_true;
}

/* zk_Verifier_v: sub program */
zk_bool zk_Verifier_v(zk_bool vVerification[1], const mpz_t vResponse[6])
{
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar416;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar417;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar418;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar419;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar420;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar421;
    /* zk_bool_t ret */
    zk_bool bVar422;
    /* CMV_IN(true) */
    zk_bool bVar423;
    /* CMM_IF(!proofs[i]->V(interactive)) */
    zk_bool bVar424;
    /* CMM_IF(!proofs[i]->V(interactive)) */
    zk_bool bVar425;
    /* CMM_IF(!proofs[i]->V(interactive)) */
    zk_bool bVar426;
    
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar24, vResponse[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar428;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar429;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar430;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar431;
            /* CMV_IN(0ul) */
            zk_ulong ulVar432;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar433;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar434;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar435;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar431 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar432 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar433 = mpz_cmp_ui(g_mpzVar24, ulVar432);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar434 = iVar433 >= iVar431;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar435 = !bVar434;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar430 = (zk_bool)bVar435;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar430)
            {
                /* CMV_IN(false) */
                zk_bool bVar436;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar436 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar428 = (zk_bool)bVar436;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar437;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar438;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar439;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar440;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar441;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar438 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar439 = mpz_cmp(g_mpzVar24, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar440 = iVar439 < iVar438;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar441 = !bVar440;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar437 = (zk_bool)bVar441;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar437)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar442;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar442 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar428 = (zk_bool)bVar442;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar443;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar443 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar428 = (zk_bool)bVar443;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar429 = !bVar428;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar416 = (zk_bool)bVar429;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar416)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar444;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar445;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar446;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar444 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar445 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar446 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar446, pccVar445, iVar444, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar25, vResponse[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar448;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar449;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar450;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar451;
            /* CMV_IN(0ul) */
            zk_ulong ulVar452;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar453;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar454;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar455;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar451 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar452 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar453 = mpz_cmp_ui(g_mpzVar25, ulVar452);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar454 = iVar453 >= iVar451;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar455 = !bVar454;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar450 = (zk_bool)bVar455;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar450)
            {
                /* CMV_IN(false) */
                zk_bool bVar456;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar456 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar448 = (zk_bool)bVar456;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar457;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar458;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar459;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar460;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar461;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar458 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar459 = mpz_cmp(g_mpzVar25, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar460 = iVar459 < iVar458;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar461 = !bVar460;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar457 = (zk_bool)bVar461;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar457)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar462;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar462 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar448 = (zk_bool)bVar462;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar463;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar463 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar448 = (zk_bool)bVar463;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar449 = !bVar448;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar417 = (zk_bool)bVar449;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar417)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar464;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar465;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar466;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar464 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar465 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar466 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar466, pccVar465, iVar464, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar31, vResponse[2]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar468;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar469;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar470;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar471;
            /* CMV_IN(0ul) */
            zk_ulong ulVar472;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar473;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar474;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar475;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar471 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar472 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar473 = mpz_cmp_ui(g_mpzVar31, ulVar472);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar474 = iVar473 >= iVar471;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar475 = !bVar474;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar470 = (zk_bool)bVar475;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar470)
            {
                /* CMV_IN(false) */
                zk_bool bVar476;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar476 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar468 = (zk_bool)bVar476;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar477;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar478;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar479;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar480;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar481;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar478 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar479 = mpz_cmp(g_mpzVar31, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar480 = iVar479 < iVar478;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar481 = !bVar480;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar477 = (zk_bool)bVar481;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar477)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar482;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar482 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar468 = (zk_bool)bVar482;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar483;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar483 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar468 = (zk_bool)bVar483;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar469 = !bVar468;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar418 = (zk_bool)bVar469;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar418)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar484;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar485;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar486;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar484 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar485 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar486 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar486, pccVar485, iVar484, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar32, vResponse[3]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar488;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar489;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar490;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar491;
            /* CMV_IN(0ul) */
            zk_ulong ulVar492;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar493;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar494;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar495;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar491 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar492 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar493 = mpz_cmp_ui(g_mpzVar32, ulVar492);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar494 = iVar493 >= iVar491;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar495 = !bVar494;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar490 = (zk_bool)bVar495;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar490)
            {
                /* CMV_IN(false) */
                zk_bool bVar496;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar496 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar488 = (zk_bool)bVar496;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar497;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar498;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar499;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar500;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar501;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar498 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar499 = mpz_cmp(g_mpzVar32, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar500 = iVar499 < iVar498;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar501 = !bVar500;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar497 = (zk_bool)bVar501;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar497)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar502;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar502 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar488 = (zk_bool)bVar502;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar503;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar503 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar488 = (zk_bool)bVar503;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar489 = !bVar488;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar419 = (zk_bool)bVar489;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar419)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar504;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar505;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar506;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar504 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar505 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar506 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar506, pccVar505, iVar504, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar38, vResponse[4]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar508;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar509;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar510;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar511;
            /* CMV_IN(0ul) */
            zk_ulong ulVar512;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar513;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar514;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar515;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar511 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar512 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar513 = mpz_cmp_ui(g_mpzVar38, ulVar512);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar514 = iVar513 >= iVar511;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar515 = !bVar514;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar510 = (zk_bool)bVar515;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar510)
            {
                /* CMV_IN(false) */
                zk_bool bVar516;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar516 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar508 = (zk_bool)bVar516;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar517;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar518;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar519;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar520;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar521;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar518 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar519 = mpz_cmp(g_mpzVar38, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar520 = iVar519 < iVar518;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar521 = !bVar520;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar517 = (zk_bool)bVar521;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar517)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar522;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar522 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar508 = (zk_bool)bVar522;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar523;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar523 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar508 = (zk_bool)bVar523;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar509 = !bVar508;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar420 = (zk_bool)bVar509;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar420)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar524;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar525;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar526;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar524 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar525 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar526 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar526, pccVar525, iVar524, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar39, vResponse[5]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar528;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar529;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar530;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar531;
            /* CMV_IN(0ul) */
            zk_ulong ulVar532;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar533;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar534;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar535;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar531 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar532 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar533 = mpz_cmp_ui(g_mpzVar39, ulVar532);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar534 = iVar533 >= iVar531;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar535 = !bVar534;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar530 = (zk_bool)bVar535;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar530)
            {
                /* CMV_IN(false) */
                zk_bool bVar536;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar536 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar528 = (zk_bool)bVar536;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar537;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar538;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar539;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar540;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar541;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar538 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar539 = mpz_cmp(g_mpzVar39, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar540 = iVar539 < iVar538;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar541 = !bVar540;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar537 = (zk_bool)bVar541;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar537)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar542;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar542 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar528 = (zk_bool)bVar542;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar543;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar543 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar528 = (zk_bool)bVar543;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar529 = !bVar528;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar421 = (zk_bool)bVar529;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar421)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar544;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar545;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar546;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar544 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar545 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar546 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar546, pccVar545, iVar544, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* construct [and.cpp:160: zk_bool_t ret] */
    /* construct [and.cpp:161: CMV_IN(true)] */
    bVar423 = zk_true;
    /* copy-assign [and.cpp:160: zk_bool_t ret] = [and.cpp:161: CMV_IN(true)] */
    bVar422 = (zk_bool)bVar423;
    /* destruct [and.cpp:161: CMV_IN(true)] */
    /* CMM_IF(!proofs[i]->V(interactive)) */
    {
        /* implicit copy of [phi.cpp:89: zk_bool_t is_equal] */
        zk_bool bVar547;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar548;
        /* zk_bool_t is_equal */
        zk_bool bVar549;
        /* bnz_t */
        mpz_t mpzVar550;
        /* bnz_t */
        mpz_t mpzVar551;
        /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
        zk_bool bVar552;
        
        /* construct [phi.cpp:89: zk_bool_t is_equal] */
        /* construct [atomic.cpp:24: bnz_t] */
        /* bnz_init(z[i]) */
        mpz_init(mpzVar550);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(g_mpzVar14, g_mpzVar12, g_mpzVar24, g_mpzVar2);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(g_mpzVar15, g_mpzVar13, g_mpzVar25, g_mpzVar2);
        /* bnz_mul(*dst, *src0, *src1) */
        mpz_mul(mpzVar550, g_mpzVar14, g_mpzVar15);
        /* bnz_mod(*dst, *dst, n) */
        mpz_mod(mpzVar550, mpzVar550, g_mpzVar2);
        /* construct [atomic.cpp:24: bnz_t] */
        /* bnz_init(z[i]) */
        mpz_init(mpzVar551);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(mpzVar551, g_mpzVar9, g_mpzVar22, g_mpzVar2);
        /* bnz_mul(*dst, *src0, *src1) */
        mpz_mul(mpzVar551, mpzVar551, g_mpzVar23);
        /* bnz_mod(*dst, *dst, n) */
        mpz_mod(mpzVar551, mpzVar551, g_mpzVar2);
        /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
        {
            /* CMV_IN(R_ID) */
            zk_relation relVar553;
            /* Relation result */
            zk_relation relVar554;
            /* return of operator [Operator.hpp:365: equalTo] */
            zk_bool bVar555;
            /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
            zk_bool bVar556;
            
            /* construct [phi.cpp:100: CMV_IN(R_ID)] */
            relVar553 = 0/*R_ID*/;
            /* construct [z_mul_n.cpp:149: Relation result] */
            /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
            {
                /* return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)] */
                zk_int iVar557;
                
                /* construct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                /* bnz_cmp(*a, *b) */
                iVar557 = mpz_cmp(mpzVar550, mpzVar551);
                /* copy-construct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] = [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                bVar556 = (zk_bool)iVar557;
                /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                if (bVar556)
                {
                    /* CMV_IN(R_UN) */
                    zk_relation relVar558;
                    
                    /* construct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                    relVar558 = 2/*R_UN*/;
                    /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                    relVar554 = relVar558;
                    /* destruct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                }
                else
                {
                    /* CMV_IN(R_ID) */
                    zk_relation relVar559;
                    
                    /* construct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                    relVar559 = 0/*R_ID*/;
                    /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                    relVar554 = relVar559;
                    /* destruct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                }
                /* destruct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] */
            }
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            /* equalTo */
            bVar555 = relVar554 == relVar553;
            /* copy-construct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            bVar552 = (zk_bool)bVar555;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            /* destruct [z_mul_n.cpp:149: Relation result] */
            /* destruct [phi.cpp:100: CMV_IN(R_ID)] */
            if (bVar552)
            {
                /* CMV_IN(true) */
                zk_bool bVar560;
                
                /* construct [phi.cpp:101: CMV_IN(true)] */
                bVar560 = zk_true;
                /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:101: CMV_IN(true)] */
                bVar549 = (zk_bool)bVar560;
                /* destruct [phi.cpp:101: CMV_IN(true)] */
            }
            else
            {
                /* CMV_IN(false) */
                zk_bool bVar561;
                
                /* construct [phi.cpp:103: CMV_IN(false)] */
                bVar561 = zk_false;
                /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:103: CMV_IN(false)] */
                bVar549 = (zk_bool)bVar561;
                /* destruct [phi.cpp:103: CMV_IN(false)] */
            }
            /* destruct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] */
        }
        /* bnz_clear(z[i]) */
        mpz_clear(mpzVar550);
        /* destruct [atomic.cpp:24: bnz_t] */
        /* bnz_clear(z[i]) */
        mpz_clear(mpzVar551);
        /* destruct [atomic.cpp:24: bnz_t] */
        /* copy-construct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] = [phi.cpp:89: zk_bool_t is_equal] */
        bVar547 = (zk_bool)bVar549;
        /* destruct [phi.cpp:89: zk_bool_t is_equal] */
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar548 = !bVar547;
        /* copy-construct [and.cpp:165: CMM_IF(!proofs[i]->V(interactive))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar424 = (zk_bool)bVar548;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] */
        if (bVar424)
        {
            /* CMV_IN(false) */
            zk_bool bVar562;
            
            /* construct [and.cpp:166: CMV_IN(false)] */
            bVar562 = zk_false;
            /* copy-assign [and.cpp:160: zk_bool_t ret] = [and.cpp:166: CMV_IN(false)] */
            bVar422 = (zk_bool)bVar562;
            /* destruct [and.cpp:166: CMV_IN(false)] */
        }
        /* destruct [and.cpp:165: CMM_IF(!proofs[i]->V(interactive))] */
    }
    /* CMM_IF(!proofs[i]->V(interactive)) */
    {
        /* implicit copy of [phi.cpp:89: zk_bool_t is_equal] */
        zk_bool bVar563;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar564;
        /* zk_bool_t is_equal */
        zk_bool bVar565;
        /* bnz_t */
        mpz_t mpzVar566;
        /* bnz_t */
        mpz_t mpzVar567;
        /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
        zk_bool bVar568;
        
        /* construct [phi.cpp:89: zk_bool_t is_equal] */
        /* construct [atomic.cpp:24: bnz_t] */
        /* bnz_init(z[i]) */
        mpz_init(mpzVar566);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(g_mpzVar14, g_mpzVar12, g_mpzVar31, g_mpzVar2);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(g_mpzVar15, g_mpzVar13, g_mpzVar32, g_mpzVar2);
        /* bnz_mul(*dst, *src0, *src1) */
        mpz_mul(mpzVar566, g_mpzVar14, g_mpzVar15);
        /* bnz_mod(*dst, *dst, n) */
        mpz_mod(mpzVar566, mpzVar566, g_mpzVar2);
        /* construct [atomic.cpp:24: bnz_t] */
        /* bnz_init(z[i]) */
        mpz_init(mpzVar567);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(mpzVar567, g_mpzVar10, g_mpzVar29, g_mpzVar2);
        /* bnz_mul(*dst, *src0, *src1) */
        mpz_mul(mpzVar567, mpzVar567, g_mpzVar30);
        /* bnz_mod(*dst, *dst, n) */
        mpz_mod(mpzVar567, mpzVar567, g_mpzVar2);
        /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
        {
            /* CMV_IN(R_ID) */
            zk_relation relVar569;
            /* Relation result */
            zk_relation relVar570;
            /* return of operator [Operator.hpp:365: equalTo] */
            zk_bool bVar571;
            /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
            zk_bool bVar572;
            
            /* construct [phi.cpp:100: CMV_IN(R_ID)] */
            relVar569 = 0/*R_ID*/;
            /* construct [z_mul_n.cpp:149: Relation result] */
            /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
            {
                /* return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)] */
                zk_int iVar573;
                
                /* construct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                /* bnz_cmp(*a, *b) */
                iVar573 = mpz_cmp(mpzVar566, mpzVar567);
                /* copy-construct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] = [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                bVar572 = (zk_bool)iVar573;
                /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                if (bVar572)
                {
                    /* CMV_IN(R_UN) */
                    zk_relation relVar574;
                    
                    /* construct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                    relVar574 = 2/*R_UN*/;
                    /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                    relVar570 = relVar574;
                    /* destruct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                }
                else
                {
                    /* CMV_IN(R_ID) */
                    zk_relation relVar575;
                    
                    /* construct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                    relVar575 = 0/*R_ID*/;
                    /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                    relVar570 = relVar575;
                    /* destruct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                }
                /* destruct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] */
            }
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            /* equalTo */
            bVar571 = relVar570 == relVar569;
            /* copy-construct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            bVar568 = (zk_bool)bVar571;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            /* destruct [z_mul_n.cpp:149: Relation result] */
            /* destruct [phi.cpp:100: CMV_IN(R_ID)] */
            if (bVar568)
            {
                /* CMV_IN(true) */
                zk_bool bVar576;
                
                /* construct [phi.cpp:101: CMV_IN(true)] */
                bVar576 = zk_true;
                /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:101: CMV_IN(true)] */
                bVar565 = (zk_bool)bVar576;
                /* destruct [phi.cpp:101: CMV_IN(true)] */
            }
            else
            {
                /* CMV_IN(false) */
                zk_bool bVar577;
                
                /* construct [phi.cpp:103: CMV_IN(false)] */
                bVar577 = zk_false;
                /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:103: CMV_IN(false)] */
                bVar565 = (zk_bool)bVar577;
                /* destruct [phi.cpp:103: CMV_IN(false)] */
            }
            /* destruct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] */
        }
        /* bnz_clear(z[i]) */
        mpz_clear(mpzVar566);
        /* destruct [atomic.cpp:24: bnz_t] */
        /* bnz_clear(z[i]) */
        mpz_clear(mpzVar567);
        /* destruct [atomic.cpp:24: bnz_t] */
        /* copy-construct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] = [phi.cpp:89: zk_bool_t is_equal] */
        bVar563 = (zk_bool)bVar565;
        /* destruct [phi.cpp:89: zk_bool_t is_equal] */
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar564 = !bVar563;
        /* copy-construct [and.cpp:165: CMM_IF(!proofs[i]->V(interactive))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar425 = (zk_bool)bVar564;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] */
        if (bVar425)
        {
            /* CMV_IN(false) */
            zk_bool bVar578;
            
            /* construct [and.cpp:166: CMV_IN(false)] */
            bVar578 = zk_false;
            /* copy-assign [and.cpp:160: zk_bool_t ret] = [and.cpp:166: CMV_IN(false)] */
            bVar422 = (zk_bool)bVar578;
            /* destruct [and.cpp:166: CMV_IN(false)] */
        }
        /* destruct [and.cpp:165: CMM_IF(!proofs[i]->V(interactive))] */
    }
    /* CMM_IF(!proofs[i]->V(interactive)) */
    {
        /* implicit copy of [phi.cpp:89: zk_bool_t is_equal] */
        zk_bool bVar579;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar580;
        /* zk_bool_t is_equal */
        zk_bool bVar581;
        /* bnz_t */
        mpz_t mpzVar582;
        /* bnz_t */
        mpz_t mpzVar583;
        /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
        zk_bool bVar584;
        
        /* construct [phi.cpp:89: zk_bool_t is_equal] */
        /* construct [atomic.cpp:24: bnz_t] */
        /* bnz_init(z[i]) */
        mpz_init(mpzVar582);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(g_mpzVar14, g_mpzVar12, g_mpzVar38, g_mpzVar2);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(g_mpzVar15, g_mpzVar13, g_mpzVar39, g_mpzVar2);
        /* bnz_mul(*dst, *src0, *src1) */
        mpz_mul(mpzVar582, g_mpzVar14, g_mpzVar15);
        /* bnz_mod(*dst, *dst, n) */
        mpz_mod(mpzVar582, mpzVar582, g_mpzVar2);
        /* construct [atomic.cpp:24: bnz_t] */
        /* bnz_init(z[i]) */
        mpz_init(mpzVar583);
        /* bnz_powm(*dst, *src0, src1, n) */
        mpz_powm(mpzVar583, g_mpzVar11, g_mpzVar36, g_mpzVar2);
        /* bnz_mul(*dst, *src0, *src1) */
        mpz_mul(mpzVar583, mpzVar583, g_mpzVar37);
        /* bnz_mod(*dst, *dst, n) */
        mpz_mod(mpzVar583, mpzVar583, g_mpzVar2);
        /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
        {
            /* CMV_IN(R_ID) */
            zk_relation relVar585;
            /* Relation result */
            zk_relation relVar586;
            /* return of operator [Operator.hpp:365: equalTo] */
            zk_bool bVar587;
            /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
            zk_bool bVar588;
            
            /* construct [phi.cpp:100: CMV_IN(R_ID)] */
            relVar585 = 0/*R_ID*/;
            /* construct [z_mul_n.cpp:149: Relation result] */
            /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
            {
                /* return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)] */
                zk_int iVar589;
                
                /* construct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                /* bnz_cmp(*a, *b) */
                iVar589 = mpz_cmp(mpzVar582, mpzVar583);
                /* copy-construct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] = [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                bVar588 = (zk_bool)iVar589;
                /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
                if (bVar588)
                {
                    /* CMV_IN(R_UN) */
                    zk_relation relVar590;
                    
                    /* construct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                    relVar590 = 2/*R_UN*/;
                    /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                    relVar586 = relVar590;
                    /* destruct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                }
                else
                {
                    /* CMV_IN(R_ID) */
                    zk_relation relVar591;
                    
                    /* construct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                    relVar591 = 0/*R_ID*/;
                    /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                    relVar586 = relVar591;
                    /* destruct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                }
                /* destruct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] */
            }
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            /* equalTo */
            bVar587 = relVar586 == relVar585;
            /* copy-construct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            bVar584 = (zk_bool)bVar587;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
            /* destruct [z_mul_n.cpp:149: Relation result] */
            /* destruct [phi.cpp:100: CMV_IN(R_ID)] */
            if (bVar584)
            {
                /* CMV_IN(true) */
                zk_bool bVar592;
                
                /* construct [phi.cpp:101: CMV_IN(true)] */
                bVar592 = zk_true;
                /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:101: CMV_IN(true)] */
                bVar581 = (zk_bool)bVar592;
                /* destruct [phi.cpp:101: CMV_IN(true)] */
            }
            else
            {
                /* CMV_IN(false) */
                zk_bool bVar593;
                
                /* construct [phi.cpp:103: CMV_IN(false)] */
                bVar593 = zk_false;
                /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:103: CMV_IN(false)] */
                bVar581 = (zk_bool)bVar593;
                /* destruct [phi.cpp:103: CMV_IN(false)] */
            }
            /* destruct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] */
        }
        /* bnz_clear(z[i]) */
        mpz_clear(mpzVar582);
        /* destruct [atomic.cpp:24: bnz_t] */
        /* bnz_clear(z[i]) */
        mpz_clear(mpzVar583);
        /* destruct [atomic.cpp:24: bnz_t] */
        /* copy-construct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] = [phi.cpp:89: zk_bool_t is_equal] */
        bVar579 = (zk_bool)bVar581;
        /* destruct [phi.cpp:89: zk_bool_t is_equal] */
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar580 = !bVar579;
        /* copy-construct [and.cpp:165: CMM_IF(!proofs[i]->V(interactive))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar426 = (zk_bool)bVar580;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] */
        if (bVar426)
        {
            /* CMV_IN(false) */
            zk_bool bVar594;
            
            /* construct [and.cpp:166: CMV_IN(false)] */
            bVar594 = zk_false;
            /* copy-assign [and.cpp:160: zk_bool_t ret] = [and.cpp:166: CMV_IN(false)] */
            bVar422 = (zk_bool)bVar594;
            /* destruct [and.cpp:166: CMV_IN(false)] */
        }
        /* destruct [and.cpp:165: CMM_IF(!proofs[i]->V(interactive))] */
    }
    /* copy-assign [ZKFileToProgramCCRCompiler.cpp:268: zk_bool_t] = [and.cpp:160: zk_bool_t ret] */
    vVerification[0] = (zk_bool)bVar422;
    /* destruct [and.cpp:160: zk_bool_t ret] */
    
    return zk_true;
}

/* zk_Verifier_free: sub program */
zk_bool zk_Verifier_free()
{
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
    /* bnz_clear(cplus) */
    mpz_clear(g_mpzVar21);
    /* bnz_clear(c) */
    mpz_clear(g_mpzVar22);
    /* destruct [sigma.cpp:40: c] */
    /* destruct [sigma.cpp:40: cplus] */
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
    /* bnz_clear(cplus) */
    mpz_clear(g_mpzVar28);
    /* bnz_clear(c) */
    mpz_clear(g_mpzVar29);
    /* destruct [sigma.cpp:40: c] */
    /* destruct [sigma.cpp:40: cplus] */
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
    /* bnz_clear(cplus) */
    mpz_clear(g_mpzVar35);
    /* bnz_clear(c) */
    mpz_clear(g_mpzVar36);
    /* destruct [sigma.cpp:40: c] */
    /* destruct [sigma.cpp:40: cplus] */
    /* bnz_clear(cplus) */
    mpz_clear(g_mpzVar19);
    /* bnz_clear(c) */
    mpz_clear(g_mpzVar20);
    /* destruct [sigma.cpp:40: c] */
    /* destruct [sigma.cpp:40: cplus] */
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
    mpz_clear(g_mpzVar3);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar4);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar5);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar6);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar7);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar8);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(g_mpzVar9);
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
    /* bnz_clear(n) */
    mpz_clear(g_mpzVar1);
    /* destruct [z_add_n.cpp:28: n] */
    /* bnz_clear(n) */
    mpz_clear(g_mpzVar2);
    /* destruct [z_mul_n.cpp:32: n] */
    
    return zk_true;
}

/* end c-source-code of program "verifier" */
