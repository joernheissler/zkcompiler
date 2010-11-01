/* begin c-source-code of program "prover" */
#include "zk_prover.h"

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

/* zk_Prover_init: sub program */
zk_bool zk_Prover_init(const mpz_t vPublicCommitment_x0[1], const mpz_t vPublicCommitment_x1[1], const mpz_t vPublicCommitment_x2[1], const mpz_t vSecret_w0[2], const mpz_t vSecret_w1[2], const mpz_t vSecret_w2[2])
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
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar55;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar56;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar57;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar58;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar59;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar60;
    /* CMV_IN(-1l) */
    zk_long lVar61;
    /* bnz_t min */
    mpz_t mpzVar62;
    /* bnz_t cp */
    mpz_t mpzVar63;
    /* CMV_IN(-1l) */
    zk_long lVar64;
    /* CMV_IN(cp) */
    mpz_t mpzVar65;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar66;
    /* CMV_IN(-1l) */
    zk_long lVar67;
    /* CMV_IN(cp) */
    mpz_t mpzVar68;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar69;
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    zk_bool bVar70;
    /* CMV_IN(-1l) */
    zk_long lVar71;
    /* CMV_IN(cp) */
    mpz_t mpzVar72;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar73;
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    zk_bool bVar74;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar75;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar76;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar77;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar78;
    
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
        zk_int iVar79;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar80;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar79 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar80 = mpz_set_str(g_mpzVar12, pccVar44, iVar79);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar46 = (zk_bool)iVar80;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar46)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar81;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar82;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar83;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar81 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar82 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar83 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar83, pccVar82, iVar81, __FILE__, __LINE__);
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
        zk_bool bVar84;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar85;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar86;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar87;
            /* CMV_IN(1ul) */
            zk_ulong ulVar88;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar89;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar90;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar87 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar88 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar89 = mpz_cmp_ui(g_mpzVar12, ulVar88);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar90 = iVar89 < iVar87;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar86 = (zk_bool)bVar90;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar86)
            {
                /* CMV_IN(false) */
                zk_bool bVar91;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar91 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar84 = (zk_bool)bVar91;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar92;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar93;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar94;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar95;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar93 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar94 = mpz_cmp(g_mpzVar12, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar95 = iVar94 >= iVar93;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar92 = (zk_bool)bVar95;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar92)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar96;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar96 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar84 = (zk_bool)bVar96;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar97;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar98;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar97);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar97, g_mpzVar12, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar99;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar100;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar101;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar102;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar99 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar100 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar101 = mpz_cmp_ui(mpzVar97, ulVar100);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar102 = iVar101 == iVar99;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar98 = (zk_bool)bVar102;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar98)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar103;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar103 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar84 = (zk_bool)bVar103;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar104;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar104 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar84 = (zk_bool)bVar104;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar97);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar85 = !bVar84;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar47 = (zk_bool)bVar85;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar47)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar105;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar106;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar107;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar105 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar106 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar107 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar107, pccVar106, iVar105, __FILE__, __LINE__);
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
        zk_int iVar108;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar109;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar108 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar109 = mpz_set_str(g_mpzVar13, pccVar48, iVar108);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar50 = (zk_bool)iVar109;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar50)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar110;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar111;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar112;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar110 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar111 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar112 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar112, pccVar111, iVar110, __FILE__, __LINE__);
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
        zk_bool bVar113;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar114;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar115;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar116;
            /* CMV_IN(1ul) */
            zk_ulong ulVar117;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar118;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar119;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar116 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar117 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar118 = mpz_cmp_ui(g_mpzVar13, ulVar117);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar119 = iVar118 < iVar116;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar115 = (zk_bool)bVar119;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar115)
            {
                /* CMV_IN(false) */
                zk_bool bVar120;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar120 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar113 = (zk_bool)bVar120;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar121;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar122;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar123;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar124;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar122 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar123 = mpz_cmp(g_mpzVar13, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar124 = iVar123 >= iVar122;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar121 = (zk_bool)bVar124;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar121)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar125;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar125 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar113 = (zk_bool)bVar125;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar126;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar127;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar126);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar126, g_mpzVar13, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar128;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar129;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar130;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar131;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar128 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar129 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar130 = mpz_cmp_ui(mpzVar126, ulVar129);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar131 = iVar130 == iVar128;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar127 = (zk_bool)bVar131;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar127)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar132;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar132 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar113 = (zk_bool)bVar132;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar133;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar133 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar113 = (zk_bool)bVar133;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar126);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar114 = !bVar113;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar51 = (zk_bool)bVar114;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar51)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar134;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar135;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar136;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar134 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar135 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar136 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar136, pccVar135, iVar134, __FILE__, __LINE__);
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
    mpz_set(g_mpzVar3, vSecret_w0[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar138;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar139;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar140;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar141;
            /* CMV_IN(0ul) */
            zk_ulong ulVar142;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar143;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar144;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar145;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar141 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar142 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar143 = mpz_cmp_ui(g_mpzVar3, ulVar142);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar144 = iVar143 >= iVar141;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar145 = !bVar144;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar140 = (zk_bool)bVar145;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar140)
            {
                /* CMV_IN(false) */
                zk_bool bVar146;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar146 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar138 = (zk_bool)bVar146;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar147;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar148;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar149;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar150;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar151;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar148 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar149 = mpz_cmp(g_mpzVar3, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar150 = iVar149 < iVar148;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar151 = !bVar150;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar147 = (zk_bool)bVar151;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar147)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar152;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar152 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar138 = (zk_bool)bVar152;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar153;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar153 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar138 = (zk_bool)bVar153;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar139 = !bVar138;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar52 = (zk_bool)bVar139;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar52)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar154;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar155;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar156;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar154 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar155 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar156 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar156, pccVar155, iVar154, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar4, vSecret_w0[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar158;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar159;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar160;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar161;
            /* CMV_IN(0ul) */
            zk_ulong ulVar162;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar163;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar164;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar165;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar161 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar162 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar163 = mpz_cmp_ui(g_mpzVar4, ulVar162);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar164 = iVar163 >= iVar161;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar165 = !bVar164;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar160 = (zk_bool)bVar165;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar160)
            {
                /* CMV_IN(false) */
                zk_bool bVar166;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar166 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar158 = (zk_bool)bVar166;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar167;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar168;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar169;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar170;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar171;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar168 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar169 = mpz_cmp(g_mpzVar4, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar170 = iVar169 < iVar168;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar171 = !bVar170;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar167 = (zk_bool)bVar171;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar167)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar172;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar172 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar158 = (zk_bool)bVar172;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar173;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar173 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar158 = (zk_bool)bVar173;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar159 = !bVar158;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar53 = (zk_bool)bVar159;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar53)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar174;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar175;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar176;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar174 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar175 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar176 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar176, pccVar175, iVar174, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar5, vSecret_w1[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar178;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar179;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar180;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar181;
            /* CMV_IN(0ul) */
            zk_ulong ulVar182;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar183;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar184;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar185;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar181 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar182 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar183 = mpz_cmp_ui(g_mpzVar5, ulVar182);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar184 = iVar183 >= iVar181;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar185 = !bVar184;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar180 = (zk_bool)bVar185;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar180)
            {
                /* CMV_IN(false) */
                zk_bool bVar186;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar186 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar178 = (zk_bool)bVar186;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar187;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar188;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar189;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar190;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar191;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar188 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar189 = mpz_cmp(g_mpzVar5, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar190 = iVar189 < iVar188;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar191 = !bVar190;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar187 = (zk_bool)bVar191;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar187)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar192;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar192 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar178 = (zk_bool)bVar192;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar193;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar193 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar178 = (zk_bool)bVar193;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar179 = !bVar178;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar54 = (zk_bool)bVar179;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar54)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar194;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar195;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar196;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar194 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar195 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar196 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar196, pccVar195, iVar194, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar6, vSecret_w1[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar198;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar199;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar200;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar201;
            /* CMV_IN(0ul) */
            zk_ulong ulVar202;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar203;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar204;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar205;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar201 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar202 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar203 = mpz_cmp_ui(g_mpzVar6, ulVar202);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar204 = iVar203 >= iVar201;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar205 = !bVar204;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar200 = (zk_bool)bVar205;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar200)
            {
                /* CMV_IN(false) */
                zk_bool bVar206;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar206 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar198 = (zk_bool)bVar206;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar207;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar208;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar209;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar210;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar211;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar208 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar209 = mpz_cmp(g_mpzVar6, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar210 = iVar209 < iVar208;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar211 = !bVar210;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar207 = (zk_bool)bVar211;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar207)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar212;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar212 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar198 = (zk_bool)bVar212;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar213;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar213 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar198 = (zk_bool)bVar213;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar199 = !bVar198;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar55 = (zk_bool)bVar199;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar55)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar214;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar215;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar216;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar214 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar215 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar216 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar216, pccVar215, iVar214, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar7, vSecret_w2[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar218;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar219;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar220;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar221;
            /* CMV_IN(0ul) */
            zk_ulong ulVar222;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar223;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar224;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar225;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar221 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar222 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar223 = mpz_cmp_ui(g_mpzVar7, ulVar222);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar224 = iVar223 >= iVar221;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar225 = !bVar224;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar220 = (zk_bool)bVar225;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar220)
            {
                /* CMV_IN(false) */
                zk_bool bVar226;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar226 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar218 = (zk_bool)bVar226;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar227;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar228;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar229;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar230;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar231;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar228 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar229 = mpz_cmp(g_mpzVar7, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar230 = iVar229 < iVar228;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar231 = !bVar230;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar227 = (zk_bool)bVar231;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar227)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar232;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar232 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar218 = (zk_bool)bVar232;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar233;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar233 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar218 = (zk_bool)bVar233;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar219 = !bVar218;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar56 = (zk_bool)bVar219;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar56)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar234;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar235;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar236;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar234 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar235 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar236 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar236, pccVar235, iVar234, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar8, vSecret_w2[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar238;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar239;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar240;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar241;
            /* CMV_IN(0ul) */
            zk_ulong ulVar242;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar243;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar244;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar245;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar241 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar242 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar243 = mpz_cmp_ui(g_mpzVar8, ulVar242);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar244 = iVar243 >= iVar241;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar245 = !bVar244;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar240 = (zk_bool)bVar245;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar240)
            {
                /* CMV_IN(false) */
                zk_bool bVar246;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar246 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar238 = (zk_bool)bVar246;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar247;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar248;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar249;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar250;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar251;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar248 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar249 = mpz_cmp(g_mpzVar8, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar250 = iVar249 < iVar248;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar251 = !bVar250;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar247 = (zk_bool)bVar251;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar247)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar252;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar252 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar238 = (zk_bool)bVar252;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar253;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar253 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar238 = (zk_bool)bVar253;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar239 = !bVar238;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar57 = (zk_bool)bVar239;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar57)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar254;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar255;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar256;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar254 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar255 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar256 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar256, pccVar255, iVar254, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar9, vPublicCommitment_x0[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar258;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar259;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar260;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar261;
            /* CMV_IN(1ul) */
            zk_ulong ulVar262;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar263;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar264;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar261 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar262 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar263 = mpz_cmp_ui(g_mpzVar9, ulVar262);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar264 = iVar263 < iVar261;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar260 = (zk_bool)bVar264;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar260)
            {
                /* CMV_IN(false) */
                zk_bool bVar265;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar265 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar258 = (zk_bool)bVar265;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar266;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar267;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar268;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar269;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar267 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar268 = mpz_cmp(g_mpzVar9, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar269 = iVar268 >= iVar267;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar266 = (zk_bool)bVar269;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar266)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar270;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar270 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar258 = (zk_bool)bVar270;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar271;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar272;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar271);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar271, g_mpzVar9, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar273;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar274;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar275;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar276;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar273 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar274 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar275 = mpz_cmp_ui(mpzVar271, ulVar274);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar276 = iVar275 == iVar273;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar272 = (zk_bool)bVar276;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar272)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar277;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar277 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar258 = (zk_bool)bVar277;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar278;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar278 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar258 = (zk_bool)bVar278;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar271);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar259 = !bVar258;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar58 = (zk_bool)bVar259;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar58)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar279;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar280;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar281;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar279 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar280 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar281 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar281, pccVar280, iVar279, __FILE__, __LINE__);
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
        zk_bool bVar283;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar284;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar285;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar286;
            /* CMV_IN(1ul) */
            zk_ulong ulVar287;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar288;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar289;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar286 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar287 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar288 = mpz_cmp_ui(g_mpzVar10, ulVar287);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar289 = iVar288 < iVar286;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar285 = (zk_bool)bVar289;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar285)
            {
                /* CMV_IN(false) */
                zk_bool bVar290;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar290 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar283 = (zk_bool)bVar290;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar291;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar292;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar293;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar294;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar292 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar293 = mpz_cmp(g_mpzVar10, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar294 = iVar293 >= iVar292;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar291 = (zk_bool)bVar294;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar291)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar295;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar295 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar283 = (zk_bool)bVar295;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar296;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar297;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar296);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar296, g_mpzVar10, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar298;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar299;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar300;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar301;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar298 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar299 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar300 = mpz_cmp_ui(mpzVar296, ulVar299);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar301 = iVar300 == iVar298;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar297 = (zk_bool)bVar301;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar297)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar302;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar302 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar283 = (zk_bool)bVar302;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar303;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar303 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar283 = (zk_bool)bVar303;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar296);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar284 = !bVar283;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar59 = (zk_bool)bVar284;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar59)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar304;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar305;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar306;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar304 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar305 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar306 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar306, pccVar305, iVar304, __FILE__, __LINE__);
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
        zk_bool bVar308;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar309;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar310;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar311;
            /* CMV_IN(1ul) */
            zk_ulong ulVar312;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar313;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar314;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar311 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar312 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar313 = mpz_cmp_ui(g_mpzVar11, ulVar312);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar314 = iVar313 < iVar311;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar310 = (zk_bool)bVar314;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar310)
            {
                /* CMV_IN(false) */
                zk_bool bVar315;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar315 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar308 = (zk_bool)bVar315;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar316;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar317;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar318;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar319;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar317 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar318 = mpz_cmp(g_mpzVar11, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar319 = iVar318 >= iVar317;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar316 = (zk_bool)bVar319;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar316)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar320;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar320 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar308 = (zk_bool)bVar320;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar321;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar322;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar321);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar321, g_mpzVar11, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar323;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar324;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar325;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar326;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar323 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar324 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar325 = mpz_cmp_ui(mpzVar321, ulVar324);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar326 = iVar325 == iVar323;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar322 = (zk_bool)bVar326;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar322)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar327;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar327 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar308 = (zk_bool)bVar327;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar328;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar328 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar308 = (zk_bool)bVar328;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar321);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar309 = !bVar308;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar60 = (zk_bool)bVar309;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar60)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar329;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar330;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar331;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar329 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar330 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar331 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar331, pccVar330, iVar329, __FILE__, __LINE__);
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
    lVar61 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar20, lVar61);
    /* destruct [sigma.cpp:43: CMV_IN(-1l)] */
    /* construct [and.cpp:40: bnz_t min] */
    /* construct [and.cpp:41: bnz_t cp] */
    /* bnz_init(min) */
    mpz_init(mpzVar62);
    /* bnz_init(cp) */
    mpz_init(mpzVar63);
    /* construct [sigma.cpp:40: cplus] */
    /* construct [sigma.cpp:40: c] */
    /* bnz_init(cplus) */
    mpz_init(g_mpzVar21);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar64 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar22, lVar64);
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
    mpz_init_set_str(mpzVar65, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar332;
        /* CMV_IN(0ul) */
        zk_ulong ulVar333;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar334;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar335;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar332 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar333 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar334 = mpz_cmp_ui(mpzVar65, ulVar333);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar335 = iVar334 < iVar332;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar66 = (zk_bool)bVar335;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar66)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar336;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar337;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar338;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar336 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar337 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar338 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar338, pccVar337, iVar336, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar21, mpzVar65);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar65);
    /* bnz_set(cplus_, cplus) */
    mpz_set(mpzVar63, g_mpzVar21);
    /* bnz_set(min, cp) */
    mpz_set(mpzVar62, mpzVar63);
    /* construct [sigma.cpp:40: cplus] */
    /* construct [sigma.cpp:40: c] */
    /* bnz_init(cplus) */
    mpz_init(g_mpzVar28);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar67 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar29, lVar67);
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
    mpz_init_set_str(mpzVar68, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar339;
        /* CMV_IN(0ul) */
        zk_ulong ulVar340;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar341;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar342;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar339 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar340 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar341 = mpz_cmp_ui(mpzVar68, ulVar340);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar342 = iVar341 < iVar339;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar69 = (zk_bool)bVar342;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar69)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar343;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar344;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar345;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar343 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar344 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar345 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar345, pccVar344, iVar343, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar28, mpzVar68);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar68);
    /* bnz_set(cplus_, cplus) */
    mpz_set(mpzVar63, g_mpzVar28);
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar346;
        /* return of function [and.cpp:54: bnz_cmp(cp, min)] */
        zk_int iVar347;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar348;
        
        /* construct [and.cpp:54: CMV_IN(0)] */
        iVar346 = 0;
        /* construct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* bnz_cmp(cp, min) */
        iVar347 = mpz_cmp(mpzVar63, mpzVar62);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar348 = iVar347 < iVar346;
        /* copy-construct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar70 = (zk_bool)bVar348;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* destruct [and.cpp:54: CMV_IN(0)] */
        if (bVar70)
        {
            /* bnz_set(min, cp) */
            mpz_set(mpzVar62, mpzVar63);
        }
        /* destruct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] */
    }
    /* construct [sigma.cpp:40: cplus] */
    /* construct [sigma.cpp:40: c] */
    /* bnz_init(cplus) */
    mpz_init(g_mpzVar35);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar71 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar36, lVar71);
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
    mpz_init_set_str(mpzVar72, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar349;
        /* CMV_IN(0ul) */
        zk_ulong ulVar350;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar351;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar352;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar349 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar350 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar351 = mpz_cmp_ui(mpzVar72, ulVar350);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar352 = iVar351 < iVar349;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar73 = (zk_bool)bVar352;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar73)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar353;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar354;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar355;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar353 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar354 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar355 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar355, pccVar354, iVar353, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar35, mpzVar72);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar72);
    /* bnz_set(cplus_, cplus) */
    mpz_set(mpzVar63, g_mpzVar35);
    /* CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar356;
        /* return of function [and.cpp:54: bnz_cmp(cp, min)] */
        zk_int iVar357;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar358;
        
        /* construct [and.cpp:54: CMV_IN(0)] */
        iVar356 = 0;
        /* construct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* bnz_cmp(cp, min) */
        iVar357 = mpz_cmp(mpzVar63, mpzVar62);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar358 = iVar357 < iVar356;
        /* copy-construct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar74 = (zk_bool)bVar358;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [and.cpp:54: bnz_cmp(cp, min)]] */
        /* destruct [and.cpp:54: CMV_IN(0)] */
        if (bVar74)
        {
            /* bnz_set(min, cp) */
            mpz_set(mpzVar62, mpzVar63);
        }
        /* destruct [and.cpp:54: CMM_IF(CMI(bnz_cmp(cp, min)) < CMV_IN(0))] */
    }
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar359;
        /* CMV_IN(0ul) */
        zk_ulong ulVar360;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar361;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar362;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar359 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar360 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar361 = mpz_cmp_ui(mpzVar62, ulVar360);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar362 = iVar361 < iVar359;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar75 = (zk_bool)bVar362;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar75)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar363;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar364;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar365;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar363 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar364 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar365 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar365, pccVar364, iVar363, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar19, mpzVar62);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar366;
        /* CMV_IN(0ul) */
        zk_ulong ulVar367;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar368;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar369;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar366 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar367 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar368 = mpz_cmp_ui(mpzVar62, ulVar367);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar369 = iVar368 < iVar366;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar76 = (zk_bool)bVar369;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar76)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar370;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar371;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar372;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar370 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar371 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar372 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar372, pccVar371, iVar370, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar21, mpzVar62);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar373;
        /* CMV_IN(0ul) */
        zk_ulong ulVar374;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar375;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar376;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar373 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar374 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar375 = mpz_cmp_ui(mpzVar62, ulVar374);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar376 = iVar375 < iVar373;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar77 = (zk_bool)bVar376;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar77)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar377;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar378;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar379;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar377 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar378 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar379 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar379, pccVar378, iVar377, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar28, mpzVar62);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar380;
        /* CMV_IN(0ul) */
        zk_ulong ulVar381;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar382;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar383;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar380 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar381 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar382 = mpz_cmp_ui(mpzVar62, ulVar381);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar383 = iVar382 < iVar380;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar78 = (zk_bool)bVar383;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar78)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar384;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar385;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar386;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar384 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar385 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar386 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar386, pccVar385, iVar384, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar35, mpzVar62);
    /* bnz_clear(min) */
    mpz_clear(mpzVar62);
    /* bnz_clear(cp) */
    mpz_clear(mpzVar63);
    /* destruct [and.cpp:41: bnz_t cp] */
    /* destruct [and.cpp:40: bnz_t min] */
    
    return zk_true;
}

/* zk_Prover_p1: sub program */
zk_bool zk_Prover_p1(mpz_t vCommitment[3])
{
    
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar26, g_mpzVar1);
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar27, g_mpzVar1);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar14, g_mpzVar12, g_mpzVar26, g_mpzVar2);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar15, g_mpzVar13, g_mpzVar27, g_mpzVar2);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar23, g_mpzVar14, g_mpzVar15);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar23, g_mpzVar23, g_mpzVar2);
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar33, g_mpzVar1);
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar34, g_mpzVar1);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar14, g_mpzVar12, g_mpzVar33, g_mpzVar2);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar15, g_mpzVar13, g_mpzVar34, g_mpzVar2);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar30, g_mpzVar14, g_mpzVar15);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar30, g_mpzVar30, g_mpzVar2);
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar40, g_mpzVar1);
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar41, g_mpzVar1);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar14, g_mpzVar12, g_mpzVar40, g_mpzVar2);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar15, g_mpzVar13, g_mpzVar41, g_mpzVar2);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar37, g_mpzVar14, g_mpzVar15);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar37, g_mpzVar37, g_mpzVar2);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[0], g_mpzVar23);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[1], g_mpzVar30);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[2], g_mpzVar37);
    
    return zk_true;
}

/* zk_Prover_p2: sub program */
zk_bool zk_Prover_p2(mpz_t vResponse[6], const mpz_t vChallenge[1])
{
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar390;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar391;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar392;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar393;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar394;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar395;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar396;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar397;
    
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar398;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar399;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar400;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar398 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar399 = mpz_cmp(vChallenge[0], g_mpzVar19);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar400 = iVar399 >= iVar398;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar390 = (zk_bool)bVar400;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar390)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar402;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar403;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar404;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar402 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar403 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar404 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar404, pccVar403, iVar402, __FILE__, __LINE__);
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
        zk_int iVar405;
        /* CMV_IN(0ul) */
        zk_ulong ulVar406;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar407;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar408;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar405 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar406 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar407 = mpz_cmp_ui(vChallenge[0], ulVar406);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar408 = iVar407 < iVar405;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar391 = (zk_bool)bVar408;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar391)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar409;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar410;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar411;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar409 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar410 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar411 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar411, pccVar410, iVar409, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar20, vChallenge[0]);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar412;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar413;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar414;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar412 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar413 = mpz_cmp(vChallenge[0], g_mpzVar21);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar414 = iVar413 >= iVar412;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar392 = (zk_bool)bVar414;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar392)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar415;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar416;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar417;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar415 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar416 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar417 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar417, pccVar416, iVar415, __FILE__, __LINE__);
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
        zk_int iVar418;
        /* CMV_IN(0ul) */
        zk_ulong ulVar419;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar420;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar421;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar418 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar419 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar420 = mpz_cmp_ui(vChallenge[0], ulVar419);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar421 = iVar420 < iVar418;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar393 = (zk_bool)bVar421;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar393)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar422;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar423;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar424;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar422 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar423 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar424 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar424, pccVar423, iVar422, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar22, vChallenge[0]);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar425;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar426;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar427;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar425 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar426 = mpz_cmp(vChallenge[0], g_mpzVar28);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar427 = iVar426 >= iVar425;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar394 = (zk_bool)bVar427;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar394)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar428;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar429;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar430;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar428 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar429 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar430 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar430, pccVar429, iVar428, __FILE__, __LINE__);
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
        zk_int iVar431;
        /* CMV_IN(0ul) */
        zk_ulong ulVar432;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar433;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar434;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar431 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar432 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar433 = mpz_cmp_ui(vChallenge[0], ulVar432);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar434 = iVar433 < iVar431;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar395 = (zk_bool)bVar434;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar395)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar435;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar436;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar437;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar435 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar436 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar437 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar437, pccVar436, iVar435, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar29, vChallenge[0]);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar438;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar439;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar440;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar438 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar439 = mpz_cmp(vChallenge[0], g_mpzVar35);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar440 = iVar439 >= iVar438;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar396 = (zk_bool)bVar440;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar396)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar441;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar442;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar443;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar441 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar442 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar443 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar443, pccVar442, iVar441, __FILE__, __LINE__);
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
        zk_int iVar444;
        /* CMV_IN(0ul) */
        zk_ulong ulVar445;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar446;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar447;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar444 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar445 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar446 = mpz_cmp_ui(vChallenge[0], ulVar445);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar447 = iVar446 < iVar444;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar397 = (zk_bool)bVar447;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar397)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar448;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar449;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar450;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar448 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar449 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar450 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar450, pccVar449, iVar448, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar36, vChallenge[0]);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar24, g_mpzVar3, g_mpzVar22);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar24, g_mpzVar24, g_mpzVar1);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar25, g_mpzVar4, g_mpzVar22);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar25, g_mpzVar25, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar24, g_mpzVar24, g_mpzVar26);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar24, g_mpzVar24, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar25, g_mpzVar25, g_mpzVar27);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar25, g_mpzVar25, g_mpzVar1);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar31, g_mpzVar5, g_mpzVar29);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar31, g_mpzVar31, g_mpzVar1);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar32, g_mpzVar6, g_mpzVar29);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar32, g_mpzVar32, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar31, g_mpzVar31, g_mpzVar33);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar31, g_mpzVar31, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar32, g_mpzVar32, g_mpzVar34);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar32, g_mpzVar32, g_mpzVar1);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar38, g_mpzVar7, g_mpzVar36);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar38, g_mpzVar38, g_mpzVar1);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar39, g_mpzVar8, g_mpzVar36);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar39, g_mpzVar39, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar38, g_mpzVar38, g_mpzVar40);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar38, g_mpzVar38, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar39, g_mpzVar39, g_mpzVar41);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar39, g_mpzVar39, g_mpzVar1);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[0], g_mpzVar24);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[1], g_mpzVar25);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[2], g_mpzVar31);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[3], g_mpzVar32);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[4], g_mpzVar38);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[5], g_mpzVar39);
    
    return zk_true;
}

/* zk_Prover_free: sub program */
zk_bool zk_Prover_free()
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

/* end c-source-code of program "prover" */
