#ifndef ZK_RANDOMSEED_H
#define ZK_RANDOMSEED_H

/** \brief get a random seed in a system defined way
 ** \param randomdata pointer to buffer of size `bytes'
 ** \param bytes size of buffer
 ** \return 0 == success, >0 errno value
 **/
unsigned long getRandomSeed(unsigned char *randomdata, unsigned int bytes);

#endif
