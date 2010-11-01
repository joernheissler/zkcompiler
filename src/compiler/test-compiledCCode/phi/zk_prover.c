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
/* cplus */
static mpz_t g_mpzVar13;
/* c */
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

/* zk_Prover_init: sub program */
zk_bool zk_Prover_init(const mpz_t vPublicCommitment_x[1], const mpz_t vSecret_w[2])
{
    /* CMV_IN(tmpN) */
    mpz_t mpzVar20;
    /* CMV_IN(tmpN) */
    mpz_t mpzVar21;
    /* zk_pcchar_t */
    zk_pcchar pccVar22;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar23;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar24;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar25;
    /* zk_pcchar_t */
    zk_pcchar pccVar26;
    /* CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]) */
    zk_pcchar pccVar27;
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    zk_bool bVar28;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar29;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar30;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar31;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar32;
    /* CMV_IN(-1l) */
    zk_long lVar33;
    /* CMV_IN(cp) */
    mpz_t mpzVar34;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar35;
    
    /* construct [z_add_n.cpp:28: n] */
    /* construct [z_add_n.cpp:41: CMV_IN(tmpN)] */
    mpz_init_set_str(mpzVar20, "509", 10);
    /* bnz_init_set(n, CMV_IN(tmpN)) */
    mpz_init_set(g_mpzVar1, mpzVar20);
    /* destruct [z_add_n.cpp:41: CMV_IN(tmpN)] */
    mpz_clear(mpzVar20);
    /* construct [z_mul_n.cpp:32: n] */
    /* construct [z_mul_n.cpp:53: CMV_IN(tmpN)] */
    mpz_init_set_str(mpzVar21, "1019", 10);
    /* bnz_init_set(n, CMV_IN(tmpN)) */
    mpz_init_set(g_mpzVar2, mpzVar21);
    /* destruct [z_mul_n.cpp:53: CMV_IN(tmpN)] */
    mpz_clear(mpzVar21);
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
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar23 = "452";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar22 = pccVar23;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar36;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar37;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar36 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar37 = mpz_set_str(g_mpzVar6, pccVar22, iVar36);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar24 = (zk_bool)iVar37;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar24)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar38;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar39;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar40;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar38 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar39 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar40 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar40, pccVar39, iVar38, __FILE__, __LINE__);
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
        zk_bool bVar41;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar42;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar43;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar44;
            /* CMV_IN(1ul) */
            zk_ulong ulVar45;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar46;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar47;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar44 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar45 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar46 = mpz_cmp_ui(g_mpzVar6, ulVar45);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar47 = iVar46 < iVar44;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar43 = (zk_bool)bVar47;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar43)
            {
                /* CMV_IN(false) */
                zk_bool bVar48;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar48 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar41 = (zk_bool)bVar48;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar49;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar50;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar51;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar52;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar50 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar51 = mpz_cmp(g_mpzVar6, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar52 = iVar51 >= iVar50;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar49 = (zk_bool)bVar52;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar49)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar53;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar53 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar41 = (zk_bool)bVar53;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar54;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar55;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar54);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar54, g_mpzVar6, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar56;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar57;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar58;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar59;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar56 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar57 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar58 = mpz_cmp_ui(mpzVar54, ulVar57);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar59 = iVar58 == iVar56;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar55 = (zk_bool)bVar59;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar55)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar60;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar60 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar41 = (zk_bool)bVar60;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar61;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar61 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar41 = (zk_bool)bVar61;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar54);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar42 = !bVar41;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar25 = (zk_bool)bVar42;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar25)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar62;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar63;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar64;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar62 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar63 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar64 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar64, pccVar63, iVar62, __FILE__, __LINE__);
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
    mpz_init(g_mpzVar7);
    /* construct [parser.cpp:211: zk_pcchar_t] */
    /* construct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar27 = "311";
    /* copy-assign [parser.cpp:211: zk_pcchar_t] = [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    pccVar26 = pccVar27;
    /* destruct [parser.cpp:213: CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j])] */
    /* CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0)))) */
    {
        /* CMV_IN(0) */
        zk_int iVar65;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar66;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar65 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar66 = mpz_set_str(g_mpzVar7, pccVar26, iVar65);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar28 = (zk_bool)iVar66;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar28)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar67;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar68;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar69;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar67 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar68 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar69 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar69, pccVar68, iVar67, __FILE__, __LINE__);
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
        zk_bool bVar70;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar71;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar72;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar73;
            /* CMV_IN(1ul) */
            zk_ulong ulVar74;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar75;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar76;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar73 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar74 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar75 = mpz_cmp_ui(g_mpzVar7, ulVar74);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar76 = iVar75 < iVar73;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar72 = (zk_bool)bVar76;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar72)
            {
                /* CMV_IN(false) */
                zk_bool bVar77;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar77 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar70 = (zk_bool)bVar77;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar78;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar79;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar80;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar81;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar79 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar80 = mpz_cmp(g_mpzVar7, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar81 = iVar80 >= iVar79;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar78 = (zk_bool)bVar81;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar78)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar82;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar82 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar70 = (zk_bool)bVar82;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar83;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar84;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar83);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar83, g_mpzVar7, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar85;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar86;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar87;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar88;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar85 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar86 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar87 = mpz_cmp_ui(mpzVar83, ulVar86);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar88 = iVar87 == iVar85;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar84 = (zk_bool)bVar88;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar84)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar89;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar89 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar70 = (zk_bool)bVar89;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar90;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar90 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar70 = (zk_bool)bVar90;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar83);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar71 = !bVar70;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar29 = (zk_bool)bVar71;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar29)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar91;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar92;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar93;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar91 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar92 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar93 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar93, pccVar92, iVar91, __FILE__, __LINE__);
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
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar3, vSecret_w[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar95;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar96;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar97;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar98;
            /* CMV_IN(0ul) */
            zk_ulong ulVar99;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar100;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar101;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar102;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar98 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar99 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar100 = mpz_cmp_ui(g_mpzVar3, ulVar99);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar101 = iVar100 >= iVar98;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar102 = !bVar101;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar97 = (zk_bool)bVar102;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar97)
            {
                /* CMV_IN(false) */
                zk_bool bVar103;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar103 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar95 = (zk_bool)bVar103;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar104;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar105;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar106;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar107;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar108;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar105 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar106 = mpz_cmp(g_mpzVar3, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar107 = iVar106 < iVar105;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar108 = !bVar107;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar104 = (zk_bool)bVar108;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar104)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar109;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar109 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar95 = (zk_bool)bVar109;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar110;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar110 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar95 = (zk_bool)bVar110;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar96 = !bVar95;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar30 = (zk_bool)bVar96;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar30)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar111;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar112;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar113;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar111 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar112 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar113 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar113, pccVar112, iVar111, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar4, vSecret_w[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar115;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar116;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar117;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar118;
            /* CMV_IN(0ul) */
            zk_ulong ulVar119;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar120;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar121;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar122;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar118 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar119 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar120 = mpz_cmp_ui(g_mpzVar4, ulVar119);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar121 = iVar120 >= iVar118;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar122 = !bVar121;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar117 = (zk_bool)bVar122;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar117)
            {
                /* CMV_IN(false) */
                zk_bool bVar123;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar123 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar115 = (zk_bool)bVar123;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar124;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar125;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar126;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar127;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar128;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar125 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar126 = mpz_cmp(g_mpzVar4, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar127 = iVar126 < iVar125;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar128 = !bVar127;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar124 = (zk_bool)bVar128;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar124)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar129;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar129 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar115 = (zk_bool)bVar129;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar130;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar130 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar115 = (zk_bool)bVar130;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar116 = !bVar115;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar31 = (zk_bool)bVar116;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar31)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar131;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar132;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar133;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar131 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar132 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar133 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar133, pccVar132, iVar131, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:241: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], src[i]) */
    mpz_set(g_mpzVar5, vPublicCommitment_x[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar135;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar136;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar137;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar138;
            /* CMV_IN(1ul) */
            zk_ulong ulVar139;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar140;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar141;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar138 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar139 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar140 = mpz_cmp_ui(g_mpzVar5, ulVar139);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar141 = iVar140 < iVar138;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar137 = (zk_bool)bVar141;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar137)
            {
                /* CMV_IN(false) */
                zk_bool bVar142;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar142 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar135 = (zk_bool)bVar142;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar143;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar144;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar145;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar146;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar144 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar145 = mpz_cmp(g_mpzVar5, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar146 = iVar145 >= iVar144;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar143 = (zk_bool)bVar146;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar143)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar147;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar147 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar135 = (zk_bool)bVar147;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar148;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar149;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar148);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar148, g_mpzVar5, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar150;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar151;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar152;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar153;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar150 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar151 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar152 = mpz_cmp_ui(mpzVar148, ulVar151);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar153 = iVar152 == iVar150;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar149 = (zk_bool)bVar153;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar149)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar154;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar154 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar135 = (zk_bool)bVar154;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar155;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar155 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar135 = (zk_bool)bVar155;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar148);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar136 = !bVar135;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar32 = (zk_bool)bVar136;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar32)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar156;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar157;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar158;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar156 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar157 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar158 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar158, pccVar157, iVar156, __FILE__, __LINE__);
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
    mpz_init(g_mpzVar13);
    /* construct [sigma.cpp:43: CMV_IN(-1l)] */
    lVar33 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar14, lVar33);
    /* destruct [sigma.cpp:43: CMV_IN(-1l)] */
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
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(g_mpzVar19);
    /* construct [phi.cpp:22: CMV_IN(cp)] */
    mpz_init_set_str(mpzVar34, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar159;
        /* CMV_IN(0ul) */
        zk_ulong ulVar160;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar161;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar162;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar159 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar160 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar161 = mpz_cmp_ui(mpzVar34, ulVar160);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar162 = iVar161 < iVar159;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar35 = (zk_bool)bVar162;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar35)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar163;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar164;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar165;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar163 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar164 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar165 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar165, pccVar164, iVar163, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar13, mpzVar34);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar34);
    
    return zk_true;
}

/* zk_Prover_p1: sub program */
zk_bool zk_Prover_p1(mpz_t vCommitment[1])
{
    
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar18, g_mpzVar1);
    /* Random::range0(*dst, n) */
    zk_Random_range0(g_mpzVar19, g_mpzVar1);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar8, g_mpzVar6, g_mpzVar18, g_mpzVar2);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar9, g_mpzVar7, g_mpzVar19, g_mpzVar2);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(g_mpzVar15, g_mpzVar8, g_mpzVar9);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar15, g_mpzVar15, g_mpzVar2);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vCommitment[0], g_mpzVar15);
    
    return zk_true;
}

/* zk_Prover_p2: sub program */
zk_bool zk_Prover_p2(mpz_t vResponse[2], const mpz_t vChallenge[1])
{
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar167;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar168;
    
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar169;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar170;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar171;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar169 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar170 = mpz_cmp(vChallenge[0], g_mpzVar13);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar171 = iVar170 >= iVar169;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar167 = (zk_bool)bVar171;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar167)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar173;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar174;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar175;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar173 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar174 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar175 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar175, pccVar174, iVar173, __FILE__, __LINE__);
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
        zk_int iVar176;
        /* CMV_IN(0ul) */
        zk_ulong ulVar177;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar178;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar179;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar176 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar177 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar178 = mpz_cmp_ui(vChallenge[0], ulVar177);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar179 = iVar178 < iVar176;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar168 = (zk_bool)bVar179;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar168)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar180;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar181;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar182;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar180 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar181 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar182 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar182, pccVar181, iVar180, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar14, vChallenge[0]);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar16, g_mpzVar3, g_mpzVar14);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar16, g_mpzVar16, g_mpzVar1);
    /* bnz_mul(*dst, *src0, src1) */
    mpz_mul(g_mpzVar17, g_mpzVar4, g_mpzVar14);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar17, g_mpzVar17, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar16, g_mpzVar16, g_mpzVar18);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar16, g_mpzVar16, g_mpzVar1);
    /* bnz_add(*dst, *src0, *src1) */
    mpz_add(g_mpzVar17, g_mpzVar17, g_mpzVar19);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(g_mpzVar17, g_mpzVar17, g_mpzVar1);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[0], g_mpzVar16);
    /* bnz_set(vDst[i], *ppDst[i]) */
    mpz_set(vResponse[1], g_mpzVar17);
    
    return zk_true;
}

/* zk_Prover_free: sub program */
zk_bool zk_Prover_free()
{
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
    /* bnz_clear(cplus) */
    mpz_clear(g_mpzVar13);
    /* bnz_clear(c) */
    mpz_clear(g_mpzVar14);
    /* destruct [sigma.cpp:40: c] */
    /* destruct [sigma.cpp:40: cplus] */
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
    /* bnz_clear(n) */
    mpz_clear(g_mpzVar1);
    /* destruct [z_add_n.cpp:28: n] */
    /* bnz_clear(n) */
    mpz_clear(g_mpzVar2);
    /* destruct [z_mul_n.cpp:32: n] */
    
    return zk_true;
}

/* end c-source-code of program "prover" */
