//
//  EntryMD5.h
//
//
//  Created by github.com/foolsparadise on 2018/6/2.
//

#include <stdio.h>
#include <string.h>
#include "EntryMD5.h"

/*
 this is only lower case 32bit
 32位小写
 */
typedef unsigned int md5_int;
struct MD5_struct
{
	md5_int A;
	md5_int B;
	md5_int C;
	md5_int D;
	md5_int lenbuf;
	char buffer[128];
};

static void md5_init(struct MD5_struct *ctx, const char *buffer);
static void md5_process(struct MD5_struct *ctx);
static void md5_buffer_full(struct MD5_struct *ctx);

/*
 for loop A\B\C\D ways
*/
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define ROT(x, s) (x = (x << s) | (x >> (32 - s)))

#define FF(a, b, c, d, j, s, T)          \
	{                                    \
		a = a + (F(b, c, d) + M[j] + T); \
		ROT(a, s);                       \
		a = a + b;                       \
	}
#define GG(a, b, c, d, j, s, T)          \
	{                                    \
		a = a + (G(b, c, d) + M[j] + T); \
		ROT(a, s);                       \
		a = a + b;                       \
	}
#define HH(a, b, c, d, j, s, T)          \
	{                                    \
		a = a + (H(b, c, d) + M[j] + T); \
		ROT(a, s);                       \
		a = a + b;                       \
	}
#define II(a, b, c, d, j, s, T)          \
	{                                    \
		a = a + (I(b, c, d) + M[j] + T); \
		ROT(a, s);                       \
		a = a + b;                       \
	}

/*
 init MD5_struct ctx
*/
static void md5_init(struct MD5_struct *ctx, const char *buffer)
{
	ctx->A = 0x67452301;
	ctx->B = 0xefcdab89;
	ctx->C = 0x98badcfe;
	ctx->D = 0x10325476;
	ctx->lenbuf = strlen(buffer);
	memcpy(ctx->buffer, buffer, ctx->lenbuf);
}

/*
 fill buffer to mod%64
*/
static void md5_buffer_full(struct MD5_struct *ctx)
{
	md5_int fullbuffer[64] = {0x80, 0};
	md5_int sizebyte[2] = {0, 0};
	md5_int len = ctx->lenbuf;
	md5_int byte = len > 56 ? (64 - (len - 56)) : 56 - len;
	memcpy(&ctx->buffer[len], fullbuffer, byte);
	sizebyte[0] += (ctx->lenbuf << 3);
	if (sizebyte[0] < ctx->lenbuf)
		sizebyte[1]++;

	memcpy(&ctx->buffer[len + byte], &sizebyte, sizeof(sizebyte));
}
/*
 deal message
*/
static void md5_process(struct MD5_struct *ctx)
{
	int i = 0;
	int j;
	md5_int M[16] = {0, 0};
	md5_int a = ctx->A;
	md5_int b = ctx->B;
	md5_int c = ctx->C;
	md5_int d = ctx->D;
	for (i = 0; i <= ctx->lenbuf; i += 64) // loop time
	{
		memcpy(M, ctx->buffer, sizeof(md5_int) * 16);

		/* round 1 */
		FF(a, b, c, d, 0, 7, 0xd76aa478);
		FF(d, a, b, c, 1, 12, 0xe8c7b756);
		FF(c, d, a, b, 2, 17, 0x242070db);
		FF(b, c, d, a, 3, 22, 0xc1bdceee);
		FF(a, b, c, d, 4, 7, 0xf57c0faf);
		FF(d, a, b, c, 5, 12, 0x4787c62a);
		FF(c, d, a, b, 6, 17, 0xa8304613);
		FF(b, c, d, a, 7, 22, 0xfd469501);
		FF(a, b, c, d, 8, 7, 0x698098d8);
		FF(d, a, b, c, 9, 12, 0x8b44f7af);
		FF(c, d, a, b, 10, 17, 0xffff5bb1);
		FF(b, c, d, a, 11, 22, 0x895cd7be);
		FF(a, b, c, d, 12, 7, 0x6b901122);
		FF(d, a, b, c, 13, 12, 0xfd987193);
		FF(c, d, a, b, 14, 17, 0xa679438e);
		FF(b, c, d, a, 15, 22, 0x49b40821);

		/* round 2 */
		GG(a, b, c, d, 1, 5, 0xf61e2562);
		GG(d, a, b, c, 6, 9, 0xc040b340);
		GG(c, d, a, b, 11, 14, 0x265e5a51);
		GG(b, c, d, a, 0, 20, 0xe9b6c7aa);
		GG(a, b, c, d, 5, 5, 0xd62f105d);
		GG(d, a, b, c, 10, 9, 0x02441453);
		GG(c, d, a, b, 15, 14, 0xd8a1e681);
		GG(b, c, d, a, 4, 20, 0xe7d3fbc8);
		GG(a, b, c, d, 9, 5, 0x21e1cde6);
		GG(d, a, b, c, 14, 9, 0xc33707d6);
		GG(c, d, a, b, 3, 14, 0xf4d50d87);
		GG(b, c, d, a, 8, 20, 0x455a14ed);
		GG(a, b, c, d, 13, 5, 0xa9e3e905);
		GG(d, a, b, c, 2, 9, 0xfcefa3f8);
		GG(c, d, a, b, 7, 14, 0x676f02d9);
		GG(b, c, d, a, 12, 20, 0x8d2a4c8a);

		/* round 3 */
		HH(a, b, c, d, 5, 4, 0xfffa3942);
		HH(d, a, b, c, 8, 11, 0x8771f681);
		HH(c, d, a, b, 11, 16, 0x6d9d6122);
		HH(b, c, d, a, 14, 23, 0xfde5380c);
		HH(a, b, c, d, 1, 4, 0xa4beea44);
		HH(d, a, b, c, 4, 11, 0x4bdecfa9);
		HH(c, d, a, b, 7, 16, 0xf6bb4b60);
		HH(b, c, d, a, 10, 23, 0xbebfbc70);
		HH(a, b, c, d, 13, 4, 0x289b7ec6);
		HH(d, a, b, c, 0, 11, 0xeaa127fa);
		HH(c, d, a, b, 3, 16, 0xd4ef3085);
		HH(b, c, d, a, 6, 23, 0x04881d05);
		HH(a, b, c, d, 9, 4, 0xd9d4d039);
		HH(d, a, b, c, 12, 11, 0xe6db99e5);
		HH(c, d, a, b, 15, 16, 0x1fa27cf8);
		HH(b, c, d, a, 2, 23, 0xc4ac5665);

		/* round 4 */
		II(a, b, c, d, 0, 6, 0xf4292244);
		II(d, a, b, c, 7, 10, 0x432aff97);
		II(c, d, a, b, 14, 15, 0xab9423a7);
		II(b, c, d, a, 5, 21, 0xfc93a039);
		II(a, b, c, d, 12, 6, 0x655b59c3);
		II(d, a, b, c, 3, 10, 0x8f0ccc92);
		II(c, d, a, b, 10, 15, 0xffeff47d);
		II(b, c, d, a, 1, 21, 0x85845dd1);
		II(a, b, c, d, 8, 6, 0x6fa87e4f);
		II(d, a, b, c, 15, 10, 0xfe2ce6e0);
		II(c, d, a, b, 6, 15, 0xa3014314);
		II(b, c, d, a, 13, 21, 0x4e0811a1);
		II(a, b, c, d, 4, 6, 0xf7537e82);
		II(d, a, b, c, 11, 10, 0xbd3af235);
		II(c, d, a, b, 2, 15, 0x2ad7d2bb);
		II(b, c, d, a, 9, 21, 0xeb86d391);

		ctx->A += a;
		ctx->B += b;
		ctx->C += c;
		ctx->D += d;
	}
}

void EntryMD5(const char *from, char *to)
{
	if (NULL == from || NULL == to)
		return;
	struct MD5_struct ctx;
	md5_init(&ctx, from);
	md5_buffer_full(&ctx);
	md5_process(&ctx);
	memset(to, 0, 32);
	unsigned char buf[20];
	memset(buf, 0, sizeof(buf));
	memcpy(buf, &ctx.A, sizeof(ctx.A));
	memcpy(buf + 4, &ctx.B, sizeof(ctx.B));
	memcpy(buf + 8, &ctx.C, sizeof(ctx.C));
	memcpy(buf + 12, &ctx.D, sizeof(ctx.D));
	sprintf(to, "%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
			buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10],
			buf[11], buf[12], buf[13], buf[14], buf[15]);
}
