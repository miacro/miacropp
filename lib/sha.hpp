/**
 * @file   sha.hpp
 * @author  fqguozhou@163.com
 * @date   Thu Jul 16 11:33:25 2015
 *
 * @brief
 *
 *
 */

#ifndef __SHA_HPP__
#define __SHA_HPP__
#include "miacropp/config.hpp"
#include "lib/utils.hpp"
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

namespace miacropp
{
  namespace sha
  {
    class sha1_type
    {
     public:
      typedef uint32_t unit_type;
      typedef std::vector<unit_type> vector;
      static const size_t HASH_LENGTH = 20;
      static const size_t CHUNK_SIZE = 64;
      static const size_t K_COUNT = 80;
      static const size_t H_COUNT = 5;
      static void
      init(vector& H, vector&)
      {
        H = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
      }
    };

    class sha224_type
    {
     public:
      typedef uint32_t unit_type;
      typedef std::vector<unit_type> vector;
      static const size_t HASH_LENGTH = 28;
      static const size_t CHUNK_SIZE = 64;
      static const size_t K_COUNT = 64;
      static const size_t H_COUNT = 8;
      static void
      init(vector& H, vector& K)
      {
        K = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
             0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
             0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
             0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
             0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
             0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
             0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
             0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
             0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
             0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
             0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
             0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
             0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
        H = {0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939,
             0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4};
      }
    };
    class sha256_type
    {
     public:
      typedef uint32_t unit_type;
      typedef std::vector<unit_type> vector;
      static const size_t HASH_LENGTH = 32;
      static const size_t CHUNK_SIZE = 64;
      static const size_t K_COUNT = 64;
      static const size_t H_COUNT = 8;
      static void
      init(vector& H, vector& K)
      {
        K = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
             0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
             0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
             0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
             0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
             0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
             0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
             0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
             0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
             0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
             0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
             0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
             0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
        H = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
             0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
      }
    };
    class sha384_type
    {
     public:
      typedef uint64_t unit_type;
      typedef std::vector<unit_type> vector;
      static const size_t HASH_LENGTH = 48;
      static const size_t CHUNK_SIZE = 128;
      static const size_t K_COUNT = 80;
      static const size_t H_COUNT = 8;
      static void
      init(vector& H, vector& K)
      {
        K = {0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
             0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
             0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
             0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
             0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
             0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
             0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
             0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
             0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
             0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
             0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
             0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
             0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
             0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
             0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
             0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
             0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
             0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
             0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
             0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
             0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
             0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
             0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
             0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
             0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
             0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
             0x5fcb6fab3ad6faec, 0x6c44198c4a475817};
        H = {0xcbbb9d5dc1059ed8, 0x629a292a367cd507, 0x9159015a3070dd17,
             0x152fecd8f70e5939, 0x67332667ffc00b31, 0x8eb44a8768581511,
             0xdb0c2e0d64f98fa7, 0x47b5481dbefa4fa4};
      }
    };
    class sha512_type
    {
     public:
      typedef uint64_t unit_type;
      typedef std::vector<unit_type> vector;
      static const size_t HASH_LENGTH = 64;
      static const size_t CHUNK_SIZE = 128;
      static const size_t K_COUNT = 80;
      static const size_t H_COUNT = 8;
      static void
      init(vector& H, vector& K)
      {
        K = {0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
             0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
             0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
             0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
             0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
             0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
             0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
             0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
             0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
             0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
             0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
             0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
             0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
             0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
             0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
             0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
             0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
             0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
             0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
             0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
             0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
             0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
             0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
             0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
             0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
             0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
             0x5fcb6fab3ad6faec, 0x6c44198c4a475817};
        H = {0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b,
             0xa54ff53a5f1d36f1, 0x510e527fade682d1, 0x9b05688c2b3e6c1f,
             0x1f83d9abfb41bd6b, 0x5be0cd19137e2179};
      }
    };

    template <typename Sha_Type>
    class sha224_512_chunk
    {
     public:
      typedef typename Sha_Type::unit_type unit_type;
      typedef typename Sha_Type::vector vector;

      static const size_t HASH_LENGTH = Sha_Type::HASH_LENGTH;
      static const size_t CHUNK_SIZE = Sha_Type::CHUNK_SIZE;
      static const size_t K_COUNT = Sha_Type::K_COUNT;
      static const size_t H_COUNT = Sha_Type::H_COUNT;
      static void
      init(vector& H, vector& K)
      {
        Sha_Type::init(H, K);
      }

     public:
      static void process_chunk(vector& H, const vector& K, unit_type* M_i);

     protected:
      static unit_type
      ROTL(size_t n, unit_type digit)
      {
        size_t bitwidth = sizeof(unit_type) * 8;
        if (n > bitwidth)
          return 0;
        return (digit << n) | (digit >> (bitwidth - n));
      }
      static unit_type
      ROTR(size_t n, unit_type digit)
      {
        size_t bitwidth = sizeof(unit_type) * 8;
        if (n > bitwidth)
          return 0;
        return (digit >> n) | (digit << (bitwidth - n));
      }

      static unit_type
      CH(unit_type x, unit_type y, unit_type z)
      {
        return (x & y) ^ ((~x) & z);
      }
      static unit_type
      MAJ(unit_type x, unit_type y, unit_type z)
      {
        return (x & y) ^ (x & z) ^ (y & z);
      }

      static uint32_t
      BSIG0(uint32_t x)
      {
        return ROTR(2, x) ^ ROTR(13, x) ^ ROTR(22, x);
      }
      static uint32_t
      BSIG1(uint32_t x)
      {
        return ROTR(6, x) ^ ROTR(11, x) ^ ROTR(25, x);
      }

      static uint32_t
      SSIG0(uint32_t x)
      {
        return ROTR(7, x) ^ ROTR(18, x) ^ (x >> 3);
      }
      static uint32_t
      SSIG1(uint32_t x)
      {
        return ROTR(17, x) ^ ROTR(19, x) ^ (x >> 10);
      }

      static uint64_t
      BSIG0(uint64_t x)
      {
        return ROTR(28, x) ^ ROTR(34, x) ^ ROTR(39, x);
      }
      static uint64_t
      BSIG1(uint64_t x)
      {
        return ROTR(14, x) ^ ROTR(18, x) ^ ROTR(41, x);
      }
      static uint64_t
      SSIG0(uint64_t x)
      {
        return ROTR(1, x) ^ ROTR(8, x) ^ (x >> 7);
      }

      static uint64_t
      SSIG1(uint64_t x)
      {
        return ROTR(19, x) ^ ROTR(61, x) ^ (x >> 6);
      }
    };

    template <typename Sha_Type>
    class sha1_chunk
    {
     public:
      typedef typename Sha_Type::unit_type unit_type;
      typedef typename Sha_Type::vector vector;

      static const size_t HASH_LENGTH = Sha_Type::HASH_LENGTH;
      static const size_t CHUNK_SIZE = Sha_Type::CHUNK_SIZE;
      static const size_t K_COUNT = Sha_Type::K_COUNT;
      static const size_t H_COUNT = Sha_Type::H_COUNT;
      static void
      init(vector& H, vector& K)
      {
        Sha_Type::init(H, K);
      }

     public:
      static void process_chunk(vector& H, const vector& K, unit_type* M_i);

     protected:
      static unit_type
      f(unit_type t, unit_type B, unit_type C, unit_type D)
      {
        if (t <= 19)
          return (B & C) | ((~B) & D);
        if ((t >= 20) && (t <= 39))
          return B ^ C ^ D;
        if ((t >= 40) && (t <= 59))
          return (B & C) | (B & D) | (C & D);
        if ((t >= 60) && (t <= 79))
          return B ^ C ^ D;
        return 0;
      }

      static unit_type
      K(unit_type t)
      {
        if (t <= 19)
          return 0x5A827999;
        if ((t >= 20) && (t <= 39))
          return 0x6ED9EBA1;
        if ((t >= 40) && (t <= 59))
          return 0x8F1BBCDC;
        if ((t >= 60) && (t <= 79))
          return 0xCA62C1D6;
        return 0;
      }
      static unit_type
      ROTL(size_t n, unit_type digit)
      {
        size_t bitwidth = sizeof(unit_type) * 8;
        if (n > bitwidth)
          return 0;
        return (digit << n) | (digit >> (bitwidth - n));
      }
    };
    template <typename Sha_Chunk>
    class sha_base
    {
     public:
      typedef typename Sha_Chunk::unit_type unit_type;
      typedef typename Sha_Chunk::vector vector;

      static const size_t HASH_LENGTH = Sha_Chunk::HASH_LENGTH;
      static const size_t CHUNK_SIZE = Sha_Chunk::CHUNK_SIZE;
      static const size_t H_COUNT = Sha_Chunk::H_COUNT;
      static void
      process_chunk(vector& H, const vector& K, unit_type* M_i)
      {
        return Sha_Chunk::process_chunk(H, K, M_i);
      }

     public:
      static int generate(char* buffer, size_t length, const char* block,
                          size_t block_size);
      static std::string generate(const char* block, size_t block_size);
      static std::string generate(const std::string& block);

     protected:
      static void process_block(vector& H, const char* block,
                                size_t block_size);
    };
    template <typename Sha_Type>
    void
    sha224_512_chunk<Sha_Type>::process_chunk(vector& H, const vector& K,
                                              unit_type* M_i)
    {
      unit_type* W = new unit_type[sha224_512_chunk::K_COUNT];
      for (size_t t = 0; t < 16; ++t)
        W[t] = utils::net_to_host(M_i[t]);
      for (size_t t = 16; t < sha224_512_chunk::K_COUNT; ++t)
        W[t] = SSIG1(W[t - 2]) + W[t - 7] + SSIG0(W[t - 15]) + W[t - 16];

      unit_type a = H[0];
      unit_type b = H[1];
      unit_type c = H[2];
      unit_type d = H[3];
      unit_type e = H[4];
      unit_type f = H[5];
      unit_type g = H[6];
      unit_type h = H[7];

      for (size_t t = 0; t < sha224_512_chunk::K_COUNT; ++t)
      {
        unit_type T1 = h + BSIG1(e) + CH(e, f, g) + K[t] + W[t];
        unit_type T2 = BSIG0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
      }
      H[0] += a;
      H[1] += b;
      H[2] += c;
      H[3] += d;
      H[4] += e;
      H[5] += f;
      H[6] += g;
      H[7] += h;
      delete[] W;
    }

    template <typename Sha_Type>
    void
    sha1_chunk<Sha_Type>::process_chunk(vector& H, const vector&,
                                        unit_type* M_i)
    {
      unit_type* W = new unit_type[sha1_chunk::K_COUNT];
      for (size_t t = 0; t < 16; ++t)
        W[t] = miacropp::utils::host_to_net(M_i[t]);
      for (size_t t = 16; t < sha1_chunk::K_COUNT; ++t)
        W[t] = sha1_chunk::ROTL(1, W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16]);

      unit_type A = H[0];
      unit_type B = H[1];
      unit_type C = H[2];
      unit_type D = H[3];
      unit_type E = H[4];
      for (size_t t = 0; t < sha1_chunk::K_COUNT; ++t)
      {
        unit_type TEMP = sha1_chunk::ROTL(5, A) + f(t, B, C, D) + E + W[t]
                         + sha1_chunk::K(t);
        E = D;
        D = C;
        C = sha1_chunk::ROTL(30, B);
        B = A;
        A = TEMP;
      }
      H[0] += A;
      H[1] += B;
      H[2] += C;
      H[3] += D;
      H[4] += E;
      delete[] W;
    }

    template <typename Sha_Chunk>
    int
    sha_base<Sha_Chunk>::generate(char* buffer, size_t length,
                                  const char* block, size_t block_size)
    {
      if (length < sha_base::HASH_LENGTH)
        return -1;

      vector H, K;
      Sha_Chunk::init(H, K);

      sha_base::process_block(H, block, block_size);
      unit_type* buffer_uint = reinterpret_cast<unit_type*>(buffer);
      for (size_t i = 0; i < sha_base::HASH_LENGTH / sizeof(unit_type); ++i)
        buffer_uint[i] = utils::host_to_net(H[i]);
      return 0;
    }

    template <typename Sha_Chunk>
    std::string
    sha_base<Sha_Chunk>::generate(const char* block, size_t block_size)
    {
      std::string buffer;
      buffer.resize(sha_base::HASH_LENGTH);
      if (sha_base::generate(const_cast<char*>(buffer.c_str()), buffer.length(),
                             block, block_size)
          == -1)
        buffer.clear();
      return buffer;
    }

    template <typename Sha_Chunk>
    std::string
    sha_base<Sha_Chunk>::generate(const std::string& block)
    {
      return sha_base::generate(block.c_str(), block.length());
    }

    template <typename Sha_Chunk>
    void
    sha_base<Sha_Chunk>::process_block(vector& H, const char* block,
                                       size_t block_size)
    {
      size_t chunk_size = sha_base::CHUNK_SIZE;
      const size_t append_length_size = sizeof(unit_type) * 2;
      size_t block_pre_count = block_size / chunk_size;
      size_t block_left_size = block_size % chunk_size;
      size_t block_pre_size = block_size - block_left_size;
      vector K;
      Sha_Chunk::init(H, K);
      for (size_t i = 0; i < block_pre_count; ++i)
      {
        unit_type* M_i = reinterpret_cast<unit_type*>(const_cast<char*>(block)
                                                      + i * chunk_size);
        sha_base::process_chunk(H, K, M_i);
      }

      char* chunk_1 = new char[chunk_size];

      std::memcpy(chunk_1, const_cast<char*>(block) + block_pre_size,
                  block_left_size);
      chunk_1[block_left_size] = 0x80;

      unit_type append_length1 = block_size >> (sizeof(unit_type) * 8 - 3);
      unit_type append_length2 = static_cast<unit_type>(block_size << 3);

      if (block_left_size + 1 + append_length_size <= chunk_size)
      {
        size_t zero_count =
            chunk_size - 1 - block_left_size - append_length_size;
        std::memset(chunk_1 + block_left_size + 1, 0, zero_count);

        unit_type* padded_chunk = reinterpret_cast<unit_type*>(
            chunk_1 + chunk_size - append_length_size);
        padded_chunk[0] = utils::host_to_net(append_length1);
        padded_chunk[1] = utils::host_to_net(append_length2);

        unit_type* M_i =
            reinterpret_cast<unit_type*>(const_cast<char*>(chunk_1));
        sha_base::process_chunk(H, K, M_i);
      }
      else
      {
        char* chunk_2 = new char[chunk_size];
        if (block_left_size + 1 < chunk_size)
          std::memset(chunk_1 + block_left_size + 1, 0,
                      chunk_size - block_left_size - 1);
        std::memset(chunk_2, 0, chunk_size - append_length_size);

        unit_type* padded_chunk = reinterpret_cast<unit_type*>(
            chunk_2 + chunk_size - append_length_size);
        padded_chunk[0] = utils::host_to_net(append_length1);
        padded_chunk[1] = utils::host_to_net(append_length2);

        unit_type* M_i =
            reinterpret_cast<unit_type*>(const_cast<char*>(chunk_1));
        sha_base::process_chunk(H, K, M_i);
        M_i = reinterpret_cast<unit_type*>(const_cast<char*>(chunk_2));
        sha_base::process_chunk(H, K, M_i);
        delete[] chunk_2;
      }
      delete[] chunk_1;
    }

    typedef sha_base<sha1_chunk<sha1_type>> sha1;
    typedef sha_base<sha224_512_chunk<sha224_type>> sha224;
    typedef sha_base<sha224_512_chunk<sha256_type>> sha256;
    typedef sha_base<sha224_512_chunk<sha384_type>> sha384;
    typedef sha_base<sha224_512_chunk<sha512_type>> sha512;
  };
};
#endif  // __SHA_HPP__
