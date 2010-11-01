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

/* zk_Verifier_init: sub program */
zk_bool zk_Verifier_init(const mpz_t vPublicCommitment_x[1])
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
    /* CMV_IN(-1l) */
    zk_long lVar31;
    /* CMV_IN(cp) */
    mpz_t mpzVar32;
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar33;
    
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
        zk_int iVar34;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar35;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar34 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar35 = mpz_set_str(g_mpzVar6, pccVar22, iVar34);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar24 = (zk_bool)iVar35;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar24)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar36;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar37;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar38;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar36 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar37 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar38 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar38, pccVar37, iVar36, __FILE__, __LINE__);
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
        zk_bool bVar39;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar40;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar41;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar42;
            /* CMV_IN(1ul) */
            zk_ulong ulVar43;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar44;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar45;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar42 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar43 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar44 = mpz_cmp_ui(g_mpzVar6, ulVar43);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar45 = iVar44 < iVar42;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar41 = (zk_bool)bVar45;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar41)
            {
                /* CMV_IN(false) */
                zk_bool bVar46;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar46 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar39 = (zk_bool)bVar46;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar47;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar48;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar49;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar50;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar48 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar49 = mpz_cmp(g_mpzVar6, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar50 = iVar49 >= iVar48;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar47 = (zk_bool)bVar50;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar47)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar51;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar51 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar39 = (zk_bool)bVar51;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar52;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar53;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar52);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar52, g_mpzVar6, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar54;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar55;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar56;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar57;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar54 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar55 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar56 = mpz_cmp_ui(mpzVar52, ulVar55);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar57 = iVar56 == iVar54;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar53 = (zk_bool)bVar57;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar53)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar58;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar58 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar39 = (zk_bool)bVar58;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar59;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar59 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar39 = (zk_bool)bVar59;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar52);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar40 = !bVar39;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar25 = (zk_bool)bVar40;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar25)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar60;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar61;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar62;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar60 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar61 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar62 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar62, pccVar61, iVar60, __FILE__, __LINE__);
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
        zk_int iVar63;
        /* return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))] */
        zk_int iVar64;
        
        /* construct [atomic.cpp:226: CMV_IN(0)] */
        iVar63 = 0;
        /* construct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* bnz_set_str(z[i], str[i], CMV_IN(0)) */
        iVar64 = mpz_set_str(g_mpzVar7, pccVar26, iVar63);
        /* copy-construct [atomic.cpp:226: CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))] = [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        bVar28 = (zk_bool)iVar64;
        /* destruct [Function.hpp:62: return of function [atomic.cpp:226: bnz_set_str(z[i], str[i], CMV_IN(0))]] */
        /* destruct [atomic.cpp:226: CMV_IN(0)] */
        if (bVar28)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar65;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar66;
            /* CMV_IN((zk_pcchar_t)("conversion error")) */
            zk_pcchar pccVar67;
            
            /* construct [atomic.cpp:227: CMV_IN(__LINE__)] */
            iVar65 = 227;
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar66 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:227: CMV_IN((zk_pcchar_t)("conversion error"))] */
            pccVar67 = "conversion error";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("conversion error"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"conversion error\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 227))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar67, pccVar66, iVar65, __FILE__, __LINE__);
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
        zk_bool bVar68;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar69;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar70;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar71;
            /* CMV_IN(1ul) */
            zk_ulong ulVar72;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar73;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar74;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar71 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar72 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar73 = mpz_cmp_ui(g_mpzVar7, ulVar72);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar74 = iVar73 < iVar71;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar70 = (zk_bool)bVar74;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar70)
            {
                /* CMV_IN(false) */
                zk_bool bVar75;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar75 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar68 = (zk_bool)bVar75;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar76;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar77;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar78;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar79;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar77 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar78 = mpz_cmp(g_mpzVar7, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar79 = iVar78 >= iVar77;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar76 = (zk_bool)bVar79;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar76)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar80;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar80 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar68 = (zk_bool)bVar80;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar81;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar82;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar81);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar81, g_mpzVar7, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar83;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar84;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar85;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar86;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar83 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar84 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar85 = mpz_cmp_ui(mpzVar81, ulVar84);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar86 = iVar85 == iVar83;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar82 = (zk_bool)bVar86;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar82)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar87;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar87 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar68 = (zk_bool)bVar87;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar88;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar88 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar68 = (zk_bool)bVar88;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar81);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar69 = !bVar68;
        /* copy-construct [atomic.cpp:230: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar29 = (zk_bool)bVar69;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar29)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar89;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar90;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar91;
            
            /* construct [atomic.cpp:231: CMV_IN(__LINE__)] */
            iVar89 = 231;
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar90 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:231: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar91 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 231))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar91, pccVar90, iVar89, __FILE__, __LINE__);
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
    mpz_set(g_mpzVar5, vPublicCommitment_x[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar93;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar94;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar95;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar96;
            /* CMV_IN(1ul) */
            zk_ulong ulVar97;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar98;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar99;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar96 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar97 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar98 = mpz_cmp_ui(g_mpzVar5, ulVar97);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar99 = iVar98 < iVar96;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar95 = (zk_bool)bVar99;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar95)
            {
                /* CMV_IN(false) */
                zk_bool bVar100;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar100 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar93 = (zk_bool)bVar100;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar101;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar102;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar103;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar104;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar102 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar103 = mpz_cmp(g_mpzVar5, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar104 = iVar103 >= iVar102;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar101 = (zk_bool)bVar104;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar101)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar105;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar105 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar93 = (zk_bool)bVar105;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar106;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar107;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar106);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar106, g_mpzVar5, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar108;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar109;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar110;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar111;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar108 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar109 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar110 = mpz_cmp_ui(mpzVar106, ulVar109);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar111 = iVar110 == iVar108;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar107 = (zk_bool)bVar111;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar107)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar112;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar112 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar93 = (zk_bool)bVar112;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar113;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar113 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar93 = (zk_bool)bVar113;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar106);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar94 = !bVar93;
        /* copy-construct [atomic.cpp:240: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar30 = (zk_bool)bVar94;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar30)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar114;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar115;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar116;
            
            /* construct [atomic.cpp:241: CMV_IN(__LINE__)] */
            iVar114 = 241;
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar115 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:241: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar116 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 241))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar116, pccVar115, iVar114, __FILE__, __LINE__);
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
    lVar31 = -1l;
    /* bnz_init_set_si(c, CMV_IN(-1l)) */
    mpz_init_set_si(g_mpzVar14, lVar31);
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
    mpz_init_set_str(mpzVar32, "509", 10);
    /* CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar117;
        /* CMV_IN(0ul) */
        zk_ulong ulVar118;
        /* return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))] */
        zk_int iVar119;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar120;
        
        /* construct [sigma.cpp:149: CMV_IN(0)] */
        iVar117 = 0;
        /* construct [sigma.cpp:149: CMV_IN(0ul)] */
        ulVar118 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus_, CMV_IN(0ul)) */
        iVar119 = mpz_cmp_ui(mpzVar32, ulVar118);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar120 = iVar119 < iVar117;
        /* copy-construct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar33 = (zk_bool)bVar120;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:149: bnz_cmp_ui(cplus_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:149: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:149: CMV_IN(0)] */
        if (bVar33)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar121;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar122;
            /* CMV_IN((zk_pcchar_t)("cplus must not be negative")) */
            zk_pcchar pccVar123;
            
            /* construct [sigma.cpp:150: CMV_IN(__LINE__)] */
            iVar121 = 150;
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar122 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            pccVar123 = "cplus must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 150))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar123, pccVar122, iVar121, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)("cplus must not be negative"))] */
            /* destruct [sigma.cpp:150: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:150: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:149: CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(cplus, cplus_) */
    mpz_set(g_mpzVar13, mpzVar32);
    /* destruct [phi.cpp:22: CMV_IN(cp)] */
    mpz_clear(mpzVar32);
    
    return zk_true;
}

/* zk_Verifier_c: sub program */
zk_bool zk_Verifier_c(mpz_t vChallenge[1], const mpz_t vCommitment[1])
{
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar124;
    /* bnz_t c_ */
    mpz_t mpzVar125;
    /* CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul)))) */
    zk_bool bVar126;
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    zk_bool bVar127;
    /* CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar128;
    /* CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0)) */
    zk_bool bVar129;
    
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar15, vCommitment[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t ret */
        zk_bool bVar131;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar132;
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        zk_bool bVar133;
        
        /* construct [z_mul_n.cpp:160: zk_bool_t ret] */
        /* CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar134;
            /* CMV_IN(1ul) */
            zk_ulong ulVar135;
            /* return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))] */
            zk_int iVar136;
            /* return of operator [Operator.hpp:368: lessThan] */
            zk_bool bVar137;
            
            /* construct [z_mul_n.cpp:163: CMV_IN(0)] */
            iVar134 = 0;
            /* construct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            ulVar135 = 1ul;
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(1ul)) */
            iVar136 = mpz_cmp_ui(g_mpzVar15, ulVar135);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* lessThan */
            bVar137 = iVar136 < iVar134;
            /* copy-construct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            bVar133 = (zk_bool)bVar137;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:163: bnz_cmp_ui(*src, CMV_IN(1ul))]] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(1ul)] */
            /* destruct [z_mul_n.cpp:163: CMV_IN(0)] */
            if (bVar133)
            {
                /* CMV_IN(false) */
                zk_bool bVar138;
                
                /* construct [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar138 = zk_false;
                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:164: CMV_IN(false)] */
                bVar131 = (zk_bool)bVar138;
                /* destruct [z_mul_n.cpp:164: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                zk_bool bVar139;
                
                /* CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0)) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar140;
                    /* return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)] */
                    zk_int iVar141;
                    /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
                    zk_bool bVar142;
                    
                    /* construct [z_mul_n.cpp:165: CMV_IN(0)] */
                    iVar140 = 0;
                    /* construct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar141 = mpz_cmp(g_mpzVar15, g_mpzVar2);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* greaterThanOrEqualTo */
                    bVar142 = iVar141 >= iVar140;
                    /* copy-construct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    bVar139 = (zk_bool)bVar142;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
                    /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:165: bnz_cmp(*src, n)]] */
                    /* destruct [z_mul_n.cpp:165: CMV_IN(0)] */
                    if (bVar139)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar143;
                        
                        /* construct [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar143 = zk_false;
                        /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:166: CMV_IN(false)] */
                        bVar131 = (zk_bool)bVar143;
                        /* destruct [z_mul_n.cpp:166: CMV_IN(false)] */
                    }
                    else
                    {
                        /* bnz_t tmp */
                        mpz_t mpzVar144;
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        zk_bool bVar145;
                        
                        /* construct [z_mul_n.cpp:169: bnz_t tmp] */
                        /* bnz_init(tmp) */
                        mpz_init(mpzVar144);
                        /* bnz_gcd(tmp, *src, n) */
                        mpz_gcd(mpzVar144, g_mpzVar15, g_mpzVar2);
                        /* CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0)) */
                        {
                            /* CMV_IN(0) */
                            zk_int iVar146;
                            /* CMV_IN(1ul) */
                            zk_ulong ulVar147;
                            /* return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))] */
                            zk_int iVar148;
                            /* return of operator [Operator.hpp:365: equalTo] */
                            zk_bool bVar149;
                            
                            /* construct [z_mul_n.cpp:173: CMV_IN(0)] */
                            iVar146 = 0;
                            /* construct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            ulVar147 = 1ul;
                            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* bnz_cmp_ui(tmp, CMV_IN(1ul)) */
                            iVar148 = mpz_cmp_ui(mpzVar144, ulVar147);
                            /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* equalTo */
                            bVar149 = iVar148 == iVar146;
                            /* copy-construct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            bVar145 = (zk_bool)bVar149;
                            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
                            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:173: bnz_cmp_ui(tmp, CMV_IN(1ul))]] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(1ul)] */
                            /* destruct [z_mul_n.cpp:173: CMV_IN(0)] */
                            if (bVar145)
                            {
                                /* CMV_IN(true) */
                                zk_bool bVar150;
                                
                                /* construct [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar150 = zk_true;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:174: CMV_IN(true)] */
                                bVar131 = (zk_bool)bVar150;
                                /* destruct [z_mul_n.cpp:174: CMV_IN(true)] */
                            }
                            else
                            {
                                /* CMV_IN(false) */
                                zk_bool bVar151;
                                
                                /* construct [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar151 = zk_false;
                                /* copy-assign [z_mul_n.cpp:160: zk_bool_t ret] = [z_mul_n.cpp:176: CMV_IN(false)] */
                                bVar131 = (zk_bool)bVar151;
                                /* destruct [z_mul_n.cpp:176: CMV_IN(false)] */
                            }
                            /* destruct [z_mul_n.cpp:173: CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))] */
                        }
                        /* bnz_clear(tmp) */
                        mpz_clear(mpzVar144);
                        /* destruct [z_mul_n.cpp:169: bnz_t tmp] */
                    }
                    /* destruct [z_mul_n.cpp:165: CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))] */
                }
            }
            /* destruct [z_mul_n.cpp:163: CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar132 = !bVar131;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar124 = (zk_bool)bVar132;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_mul_n.cpp:160: zk_bool_t ret] */
        if (bVar124)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar152;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar153;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar154;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar152 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar153 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar154 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar154, pccVar153, iVar152, __FILE__, __LINE__);
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
        zk_ulong ulVar155;
        /* return of function [sigma.cpp:60: bnz_cmp_ui(cplus, CMV_IN(0ul))] */
        zk_int iVar156;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar157;
        
        /* construct [sigma.cpp:60: CMV_IN(0ul)] */
        ulVar155 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:60: bnz_cmp_ui(cplus, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(cplus, CMV_IN(0ul)) */
        iVar156 = mpz_cmp_ui(g_mpzVar13, ulVar155);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar157 = !iVar156;
        /* copy-construct [sigma.cpp:60: CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul))))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar126 = (zk_bool)bVar157;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:60: bnz_cmp_ui(cplus, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:60: CMV_IN(0ul)] */
        if (bVar126)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar158;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar159;
            /* CMV_IN((zk_pcchar_t)("cplus not set")) */
            zk_pcchar pccVar160;
            
            /* construct [sigma.cpp:61: CMV_IN(__LINE__)] */
            iVar158 = 61;
            /* construct [sigma.cpp:61: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar159 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:61: CMV_IN((zk_pcchar_t)("cplus not set"))] */
            pccVar160 = "cplus not set";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("cplus not set"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"cplus not set\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 61))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar160, pccVar159, iVar158, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:61: CMV_IN((zk_pcchar_t)("cplus not set"))] */
            /* destruct [sigma.cpp:61: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:61: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:60: CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul))))] */
    }
    /* bnz_init(c_) */
    mpz_init(mpzVar125);
    /* Random::range0(c_, cplus) */
    zk_Random_range0(mpzVar125, g_mpzVar13);
    /* CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar161;
        /* return of function [sigma.cpp:73: bnz_cmp(c_, cplus)] */
        zk_int iVar162;
        /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
        zk_bool bVar163;
        
        /* construct [sigma.cpp:73: CMV_IN(0)] */
        iVar161 = 0;
        /* construct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* bnz_cmp(c_, cplus) */
        iVar162 = mpz_cmp(mpzVar125, g_mpzVar13);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* greaterThanOrEqualTo */
        bVar163 = iVar162 >= iVar161;
        /* copy-construct [sigma.cpp:73: CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        bVar127 = (zk_bool)bVar163;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:73: bnz_cmp(c_, cplus)]] */
        /* destruct [sigma.cpp:73: CMV_IN(0)] */
        if (bVar127)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar164;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar165;
            /* CMV_IN((zk_pcchar_t)("c must be smaller than cplus")) */
            zk_pcchar pccVar166;
            
            /* construct [sigma.cpp:74: CMV_IN(__LINE__)] */
            iVar164 = 74;
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar165 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:74: CMV_IN((zk_pcchar_t)("c must be smaller than cplus"))] */
            pccVar166 = "c must be smaller than cplus";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must be smaller than cplus"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must be smaller than cplus\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 74))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar166, pccVar165, iVar164, __FILE__, __LINE__);
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
        zk_int iVar167;
        /* CMV_IN(0ul) */
        zk_ulong ulVar168;
        /* return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))] */
        zk_int iVar169;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar170;
        
        /* construct [sigma.cpp:76: CMV_IN(0)] */
        iVar167 = 0;
        /* construct [sigma.cpp:76: CMV_IN(0ul)] */
        ulVar168 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c_, CMV_IN(0ul)) */
        iVar169 = mpz_cmp_ui(mpzVar125, ulVar168);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar170 = iVar169 < iVar167;
        /* copy-construct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar128 = (zk_bool)bVar170;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:76: bnz_cmp_ui(c_, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:76: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:76: CMV_IN(0)] */
        if (bVar128)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar171;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar172;
            /* CMV_IN((zk_pcchar_t)("c must not be negative")) */
            zk_pcchar pccVar173;
            
            /* construct [sigma.cpp:77: CMV_IN(__LINE__)] */
            iVar171 = 77;
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar172 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            pccVar173 = "c must not be negative";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("c must not be negative"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"c must not be negative\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 77))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar173, pccVar172, iVar171, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)("c must not be negative"))] */
            /* destruct [sigma.cpp:77: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:77: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:76: CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c, c_) */
    mpz_set(g_mpzVar14, mpzVar125);
    /* bnz_clear(c_) */
    mpz_clear(mpzVar125);
    /* destruct [sigma.cpp:59: bnz_t c_] */
    /* CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0)) */
    {
        /* CMV_IN(0) */
        zk_int iVar174;
        /* CMV_IN(0ul) */
        zk_ulong ulVar175;
        /* return of function [sigma.cpp:98: bnz_cmp_ui(c, CMV_IN(0ul))] */
        zk_int iVar176;
        /* return of operator [Operator.hpp:368: lessThan] */
        zk_bool bVar177;
        
        /* construct [sigma.cpp:98: CMV_IN(0)] */
        iVar174 = 0;
        /* construct [sigma.cpp:98: CMV_IN(0ul)] */
        ulVar175 = 0ul;
        /* construct [Function.hpp:62: return of function [sigma.cpp:98: bnz_cmp_ui(c, CMV_IN(0ul))]] */
        /* bnz_cmp_ui(c, CMV_IN(0ul)) */
        iVar176 = mpz_cmp_ui(g_mpzVar14, ulVar175);
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* lessThan */
        bVar177 = iVar176 < iVar174;
        /* copy-construct [sigma.cpp:98: CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0))] = [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        bVar129 = (zk_bool)bVar177;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
        /* destruct [Function.hpp:62: return of function [sigma.cpp:98: bnz_cmp_ui(c, CMV_IN(0ul))]] */
        /* destruct [sigma.cpp:98: CMV_IN(0ul)] */
        /* destruct [sigma.cpp:98: CMV_IN(0)] */
        if (bVar129)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar178;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar179;
            /* CMV_IN((zk_pcchar_t)("challenge not set")) */
            zk_pcchar pccVar180;
            
            /* construct [sigma.cpp:99: CMV_IN(__LINE__)] */
            iVar178 = 99;
            /* construct [sigma.cpp:99: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar179 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp";
            /* construct [sigma.cpp:99: CMV_IN((zk_pcchar_t)("challenge not set"))] */
            pccVar180 = "challenge not set";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("challenge not set"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"challenge not set\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/sigma/sigma.cpp", 99))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar180, pccVar179, iVar178, __FILE__, __LINE__);
            return zk_false;
            /* destruct [sigma.cpp:99: CMV_IN((zk_pcchar_t)("challenge not set"))] */
            /* destruct [sigma.cpp:99: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [sigma.cpp:99: CMV_IN(__LINE__)] */
        }
        /* destruct [sigma.cpp:98: CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0))] */
    }
    /* bnz_set(c_, c) */
    mpz_set(vChallenge[0], g_mpzVar14);
    
    return zk_true;
}

/* zk_Verifier_v: sub program */
zk_bool zk_Verifier_v(zk_bool vVerification[1], const mpz_t vResponse[2])
{
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar182;
    /* CMM_IF(!g->inGroup(z)) */
    zk_bool bVar183;
    /* zk_bool_t is_equal */
    zk_bool bVar184;
    /* bnz_t */
    mpz_t mpzVar185;
    /* bnz_t */
    mpz_t mpzVar186;
    /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
    zk_bool bVar187;
    /* implicit copy of [phi.cpp:89: zk_bool_t is_equal] */
    zk_bool bVar188;
    
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar16, vResponse[0]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar190;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar191;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar192;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar193;
            /* CMV_IN(0ul) */
            zk_ulong ulVar194;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar195;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar196;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar197;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar193 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar194 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar195 = mpz_cmp_ui(g_mpzVar16, ulVar194);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar196 = iVar195 >= iVar193;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar197 = !bVar196;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar192 = (zk_bool)bVar197;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar192)
            {
                /* CMV_IN(false) */
                zk_bool bVar198;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar198 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar190 = (zk_bool)bVar198;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar199;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar200;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar201;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar202;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar203;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar200 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar201 = mpz_cmp(g_mpzVar16, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar202 = iVar201 < iVar200;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar203 = !bVar202;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar199 = (zk_bool)bVar203;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar199)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar204;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar204 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar190 = (zk_bool)bVar204;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar205;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar205 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar190 = (zk_bool)bVar205;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar191 = !bVar190;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar182 = (zk_bool)bVar191;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar182)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar206;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar207;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar208;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar206 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar207 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar208 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar208, pccVar207, iVar206, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* bnz_set(z[i], *vpSrc[i]) */
    mpz_set(g_mpzVar17, vResponse[1]);
    /* CMM_IF(!g->inGroup(z)) */
    {
        /* zk_bool_t result */
        zk_bool bVar210;
        /* return of operator [Operator.hpp:373: logicalNegation] */
        zk_bool bVar211;
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        zk_bool bVar212;
        
        /* construct [z_add_n.cpp:126: zk_bool_t result] */
        /* CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0))) */
        {
            /* CMV_IN(0) */
            zk_int iVar213;
            /* CMV_IN(0ul) */
            zk_ulong ulVar214;
            /* return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))] */
            zk_int iVar215;
            /* return of operator [Operator.hpp:369: greaterThanOrEqualTo] */
            zk_bool bVar216;
            /* return of operator [Operator.hpp:373: logicalNegation] */
            zk_bool bVar217;
            
            /* construct [z_add_n.cpp:127: CMV_IN(0)] */
            iVar213 = 0;
            /* construct [z_add_n.cpp:127: CMV_IN(0ul)] */
            ulVar214 = 0ul;
            /* construct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* bnz_cmp_ui(*src, CMV_IN(0ul)) */
            iVar215 = mpz_cmp_ui(g_mpzVar17, ulVar214);
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* greaterThanOrEqualTo */
            bVar216 = iVar215 >= iVar213;
            /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* logicalNegation */
            bVar217 = !bVar216;
            /* copy-construct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            bVar212 = (zk_bool)bVar217;
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
            /* destruct [Operator.hpp:33: return of operator [Operator.hpp:369: greaterThanOrEqualTo]] */
            /* destruct [Function.hpp:62: return of function [z_add_n.cpp:127: bnz_cmp_ui(*src, CMV_IN(0ul))]] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0ul)] */
            /* destruct [z_add_n.cpp:127: CMV_IN(0)] */
            if (bVar212)
            {
                /* CMV_IN(false) */
                zk_bool bVar218;
                
                /* construct [z_add_n.cpp:128: CMV_IN(false)] */
                bVar218 = zk_false;
                /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:128: CMV_IN(false)] */
                bVar210 = (zk_bool)bVar218;
                /* destruct [z_add_n.cpp:128: CMV_IN(false)] */
            }
            else
            {
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                zk_bool bVar219;
                
                /* CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0))) */
                {
                    /* CMV_IN(0) */
                    zk_int iVar220;
                    /* return of function [z_add_n.cpp:129: bnz_cmp(*src, n)] */
                    zk_int iVar221;
                    /* return of operator [Operator.hpp:368: lessThan] */
                    zk_bool bVar222;
                    /* return of operator [Operator.hpp:373: logicalNegation] */
                    zk_bool bVar223;
                    
                    /* construct [z_add_n.cpp:129: CMV_IN(0)] */
                    iVar220 = 0;
                    /* construct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* bnz_cmp(*src, n) */
                    iVar221 = mpz_cmp(g_mpzVar17, g_mpzVar1);
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* lessThan */
                    bVar222 = iVar221 < iVar220;
                    /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* logicalNegation */
                    bVar223 = !bVar222;
                    /* copy-construct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    bVar219 = (zk_bool)bVar223;
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
                    /* destruct [Operator.hpp:33: return of operator [Operator.hpp:368: lessThan]] */
                    /* destruct [Function.hpp:62: return of function [z_add_n.cpp:129: bnz_cmp(*src, n)]] */
                    /* destruct [z_add_n.cpp:129: CMV_IN(0)] */
                    if (bVar219)
                    {
                        /* CMV_IN(false) */
                        zk_bool bVar224;
                        
                        /* construct [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar224 = zk_false;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:130: CMV_IN(false)] */
                        bVar210 = (zk_bool)bVar224;
                        /* destruct [z_add_n.cpp:130: CMV_IN(false)] */
                    }
                    else
                    {
                        /* CMV_IN(true) */
                        zk_bool bVar225;
                        
                        /* construct [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar225 = zk_true;
                        /* copy-assign [z_add_n.cpp:126: zk_bool_t result] = [z_add_n.cpp:132: CMV_IN(true)] */
                        bVar210 = (zk_bool)bVar225;
                        /* destruct [z_add_n.cpp:132: CMV_IN(true)] */
                    }
                    /* destruct [z_add_n.cpp:129: CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))] */
                }
            }
            /* destruct [z_add_n.cpp:127: CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* logicalNegation */
        bVar211 = !bVar210;
        /* copy-construct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] = [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        bVar183 = (zk_bool)bVar211;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:373: logicalNegation]] */
        /* destruct [z_add_n.cpp:126: zk_bool_t result] */
        if (bVar183)
        {
            /* CMV_IN(__LINE__) */
            zk_int iVar226;
            /* CMV_IN((zk_pcchar_t)__FILE__) */
            zk_pcchar pccVar227;
            /* CMV_IN((zk_pcchar_t)("element not in group")) */
            zk_pcchar pccVar228;
            
            /* construct [atomic.cpp:251: CMV_IN(__LINE__)] */
            iVar226 = 251;
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            pccVar227 = "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp";
            /* construct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            pccVar228 = "element not in group";
            /* handle_error((CodeManagement::getFromSourceVariableFactory(((zk_pcchar_t)("element not in group"))).create(CodeManagement::DebugInfo("CMV_IN(" "(zk_pcchar_t)(\"element not in group\")" ")", "/home/denis/Dokumente/Uni/Studium/Bachelorarbeit/eclipse_workspace/ZKCompiler/src/element/atomic.cpp", 251))), CMV_IN((zk_pcchar_t)__FILE__), CMV_IN(__LINE__)) */
            zk_handle_error(pccVar228, pccVar227, iVar226, __FILE__, __LINE__);
            return zk_false;
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)("element not in group"))] */
            /* destruct [atomic.cpp:251: CMV_IN((zk_pcchar_t)__FILE__)] */
            /* destruct [atomic.cpp:251: CMV_IN(__LINE__)] */
        }
        /* destruct [atomic.cpp:250: CMM_IF(!g->inGroup(z))] */
    }
    /* construct [phi.cpp:89: zk_bool_t is_equal] */
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar185);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar8, g_mpzVar6, g_mpzVar16, g_mpzVar2);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(g_mpzVar9, g_mpzVar7, g_mpzVar17, g_mpzVar2);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(mpzVar185, g_mpzVar8, g_mpzVar9);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(mpzVar185, mpzVar185, g_mpzVar2);
    /* construct [atomic.cpp:24: bnz_t] */
    /* bnz_init(z[i]) */
    mpz_init(mpzVar186);
    /* bnz_powm(*dst, *src0, src1, n) */
    mpz_powm(mpzVar186, g_mpzVar5, g_mpzVar14, g_mpzVar2);
    /* bnz_mul(*dst, *src0, *src1) */
    mpz_mul(mpzVar186, mpzVar186, g_mpzVar15);
    /* bnz_mod(*dst, *dst, n) */
    mpz_mod(mpzVar186, mpzVar186, g_mpzVar2);
    /* CMM_IF((left->cmp(right) == CMV_IN(R_ID))) */
    {
        /* CMV_IN(R_ID) */
        zk_relation relVar229;
        /* Relation result */
        zk_relation relVar230;
        /* return of operator [Operator.hpp:365: equalTo] */
        zk_bool bVar231;
        /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
        zk_bool bVar232;
        
        /* construct [phi.cpp:100: CMV_IN(R_ID)] */
        relVar229 = 0/*R_ID*/;
        /* construct [z_mul_n.cpp:149: Relation result] */
        /* CMM_IF(CMI(bnz_cmp(*a, *b))) */
        {
            /* return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)] */
            zk_int iVar233;
            
            /* construct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
            /* bnz_cmp(*a, *b) */
            iVar233 = mpz_cmp(mpzVar185, mpzVar186);
            /* copy-construct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] = [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
            bVar232 = (zk_bool)iVar233;
            /* destruct [Function.hpp:62: return of function [z_mul_n.cpp:150: bnz_cmp(*a, *b)]] */
            if (bVar232)
            {
                /* CMV_IN(R_UN) */
                zk_relation relVar234;
                
                /* construct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                relVar234 = 2/*R_UN*/;
                /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:151: CMV_IN(R_UN)] */
                relVar230 = relVar234;
                /* destruct [z_mul_n.cpp:151: CMV_IN(R_UN)] */
            }
            else
            {
                /* CMV_IN(R_ID) */
                zk_relation relVar235;
                
                /* construct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                relVar235 = 0/*R_ID*/;
                /* copy-assign [z_mul_n.cpp:149: Relation result] = [z_mul_n.cpp:153: CMV_IN(R_ID)] */
                relVar230 = relVar235;
                /* destruct [z_mul_n.cpp:153: CMV_IN(R_ID)] */
            }
            /* destruct [z_mul_n.cpp:150: CMM_IF(CMI(bnz_cmp(*a, *b)))] */
        }
        /* construct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
        /* equalTo */
        bVar231 = relVar230 == relVar229;
        /* copy-construct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] = [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
        bVar187 = (zk_bool)bVar231;
        /* destruct [Operator.hpp:33: return of operator [Operator.hpp:365: equalTo]] */
        /* destruct [z_mul_n.cpp:149: Relation result] */
        /* destruct [phi.cpp:100: CMV_IN(R_ID)] */
        if (bVar187)
        {
            /* CMV_IN(true) */
            zk_bool bVar236;
            
            /* construct [phi.cpp:101: CMV_IN(true)] */
            bVar236 = zk_true;
            /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:101: CMV_IN(true)] */
            bVar184 = (zk_bool)bVar236;
            /* destruct [phi.cpp:101: CMV_IN(true)] */
        }
        else
        {
            /* CMV_IN(false) */
            zk_bool bVar237;
            
            /* construct [phi.cpp:103: CMV_IN(false)] */
            bVar237 = zk_false;
            /* copy-assign [phi.cpp:89: zk_bool_t is_equal] = [phi.cpp:103: CMV_IN(false)] */
            bVar184 = (zk_bool)bVar237;
            /* destruct [phi.cpp:103: CMV_IN(false)] */
        }
        /* destruct [phi.cpp:100: CMM_IF((left->cmp(right) == CMV_IN(R_ID)))] */
    }
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar185);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* bnz_clear(z[i]) */
    mpz_clear(mpzVar186);
    /* destruct [atomic.cpp:24: bnz_t] */
    /* copy-construct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] = [phi.cpp:89: zk_bool_t is_equal] */
    bVar188 = (zk_bool)bVar184;
    /* destruct [phi.cpp:89: zk_bool_t is_equal] */
    /* copy-assign [ZKFileToProgramCCRCompiler.cpp:268: zk_bool_t] = [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] */
    vVerification[0] = (zk_bool)bVar188;
    /* destruct [CopyableVariable.hpp:62: implicit copy of [phi.cpp:89: zk_bool_t is_equal]] */
    
    return zk_true;
}

/* zk_Verifier_free: sub program */
zk_bool zk_Verifier_free()
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

/* end c-source-code of program "verifier" */
