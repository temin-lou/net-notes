根据[wiki](https://en.bitcoin.it/wiki/Technical_background_of_version_1_Bitcoin_addresses#How_to_create_Bitcoin_Address),我们需要先得到 
ECDSA private key, ECDSA 是 Elliptic Curve Digital Signature Algorithm 的缩写, 即椭圆曲线数字签名算法, 然后得到 
public key, 再用 public key 计算钱包地址.

#### 1 ECDSA private key
我们执行 openssl 命令

```
#shell
openssl ecparam -name secp256k1 -genkey >  priv.pem
# private key
openssl ec -in priv.pem -outform DER|tail -c +8|head -c 32|xxd -p -c 32
read EC key
writing EC key
ccea9c5a20e2b78c2e0fbdd8ae2d2b67e6b1894ccb7a55fc1de08bd53994ea64 
```
priv.pem 就是秘钥文件, 需要转成 DER 格式的, 长度是 64 
`ccea9c5a20e2b78c2e0fbdd8ae2d2b67e6b1894ccb7a55fc1de08bd53994ea64`
#### 2 ECDSA public key

```
#shell
# public key
openssl ec -in priv.pem -pubout -outform DER|tail -c 65|xxd -p -c 65
read EC key
writing EC key
04d061e9c5891f579fd548cfd22ff29f5c642714cc7e7a9215f0071ef5a5723f691757b28e31be71f09f24673eed52348e58d53bcfd26f4d96ec6bf1489eab429d
```
同样转成 DER 格式的, 长度是 130 
`04d061e9c5891f579fd548cfd22ff29f5c642714cc7e7a9215f0071ef5a5723f691757b28e31be71f09f24673eed52348e58d53bcfd26f4d96ec6bf1489eab429d`
#### 3 把上一步得到的 public key 进行 hash160
hash160 就是执行下 SHA256, 再执行下 RMD160 后的结果
```
  bytes = [pub].pack("H*") # 转化成 16 进制
  Digest::RMD160.hexdigest Digest::SHA256.digest(bytes)
```
得到 2b6f3b9e337cedbb7c40839523fb1100709c12f7
#### 4 在第 3 步得到的结果上加上 version, 一般是`00`
```
'00'+ '2b6f3b9e337cedbb7c40839523fb1100709c12f7'
```
`002b6f3b9e337cedbb7c40839523fb1100709c12f7`
#### 5 在第 4 部的结果上, 执行 2 次 SHA256, 取前 8 位作为校验和
```
b = [val].pack("H*")
Digest::SHA256.hexdigest( Digest::SHA256.digest(b) )[0...8]
```
`86b2e90c`
#### 6 把第 4 步 第 5 步的结果合并
```
'002b6f3b9e337cedbb7c40839523fb1100709c12f7' + '86b2e90c'

```
`002b6f3b9e337cedbb7c40839523fb1100709c12f786b2e90c`

#### 7 把第 6 步的结果做 base58 编码

Base58 是用于 Bitcoin 中使用的一种独特的编码方式,主要用于产生 Bitcoin 的钱包地址. 相比 Base64, Base58 
去掉了数字`0`,大写字母`O`,大写字母`I`和小写字母`l`, 以及`+`和`/`, 避免视觉的混淆.

```
    def int_to_base58(int_val, leading_zero_bytes=0)
      alpha = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"
      base58_val, base = '', alpha.size
      while int_val > 0
        int_val, remainder = int_val.divmod(base)
        base58_val = alpha[remainder] + base58_val
      end
      base58_val
    end

```
```
val = "002b6f3b9e337cedbb7c40839523fb1100709c12f786b2e90c"
leading_zero_bytes  = (val.match(/^([0]+)/) ? $1 : '').size / 2 
# leading_zero_bytes 的作用是字母填充, 待研究下

("1"*leading_zero_bytes) + int_to_base58( val.to_i(16) )

```

得到 `14xfJr1DArtYR156XBs28FoYk6sQqirT2s`,
这就是了一个标准的 bitcoin 地址

* * *
这么麻烦的事,当然有类库代劳了
使用 [bitcoin-ruby](https://github.com/lian/bitcoin-ruby) 生成 bitcoin 地址

```
require 'bitcoin'
pri_key, pub_key = Bitcoin.generate_key # 私钥 公钥都得到了
# 看下了源码, 是通过 ffi 调用 openssl 得到的
address =  Bitcoin::pubkey_to_address(pub_key)

```
* * *

在 bitcoin 系统中,私钥能得公钥, 公钥能得到钱包地址, 私钥=>公钥 =>钱包地址, 而反向是不可能的. **牢记你的私钥**, 
谁掌握私钥, 谁就拥有 btc!
