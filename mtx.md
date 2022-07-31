# send a tx on Bitcoin testnet
## 在编辑状态下便于查看

## 在虚拟机中实现，以下利用script进行打印


Script started on 2022-07-28 17:21:54+08:00 [TERM="xterm-256color" TTY="/dev/pts/0" COLUMNS="79" LINES="22"]
]0;jx05lan@jx05lan-VirtualBox: ~[01;32mjx05lan@jx05lan-VirtualBox[00m:[01;34m~[00m$ exitsudo docker run -t -i -p 19001:19001 -p 19011:19011 freewil/bitcoin-testnet-box
[sudo] password for jx05lan: 
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ make start
bitcoind -datadir=1  -daemon
Bitcoin Core starting
bitcoind -datadir=2  -daemon
Bitcoin Core starting
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ make getinfo
bitcoin-cli -datadir=1  -getinfo
{
  "version": 210000,
  "blocks": 0,
  "headers": 0,
  "verificationprogress": 1,
  "timeoffset": 0,
  "connections": {
    "in": 1,
    "out": 0,
    "total": 1
  },
  "proxy": "",
  "difficulty": 4.656542373906925e-10,
  "chain": "regtest",
  "relayfee": 0.00001000,
  "warnings": ""
}
bitcoin-cli -datadir=2  -getinfo
{
  "version": 210000,
  "blocks": 0,
  "headers": 0,
  "verificationprogress": 1,
  "timeoffset": 0,
  "connections": {
    "in": 0,
    "out": 1,
    "total": 1
  },
  "proxy": "",
  "difficulty": 4.656542373906925e-10,
  "chain": "regtest",
  "relayfee": 0.00001000,
  "warnings": ""
}
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1 createwallet  
"tets  st1"
{
  "name": "test1",
  "warning": ""
}
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ [Kbitcoin-cli -datadir=1 createwallet "
"test1"[1P"2""
[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1 createwallet createwallet "t[1P[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=2 createwallet "[1@t[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=2


{
  "name": "test2",
  "warning": ""
}
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ [Kbitcoin-cli -datadir=2 createwallet "
"test2"       [A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=2 createwallet  
[K[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=2 createwallet[K

[K[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=2 createwallet            getnewaddress 
[A[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=2 getnewaddres[Ks
bcrt1qdejfeswfskz6a9vx8pqa4z77rjtzxenu6zn6te
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ [Kbitcoin-cli -datadir=2 getnewaddress 
[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=2 getnewaddres2[1P

[K[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1 getnewaddress [A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1

bcrt1qc0evl8u8jfpnccy3rktmsj5wd2jurv3ta4pj49
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ [Kbitcoin-cli -datadir=1 getnewaddress 
[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1 getnewaddres[K

[K[A
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1 getnewaddres         walletinfo 
[A[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1 getwalletinf[Ko
{
  "walletname": "test1",
  "walletversion": 169900,
  "format": "bdb",
  "balance": 0.00000000,
  "unconfirmed_balance": 0.00000000,
  "immature_balance": 0.00000000,
  "txcount": 0,
  "keypoololdest": 1659000272,
  "keypoolsize": 999,
  "hdseedid": "477d9c1bc4de01a1cdfbc95c719f68ad6849409a",
  "keypoolsize_hd_internal": 1000,
  "paytxfee": 0.00000000,
  "private_keys_enabled": true,
  "avoid_reuse": false,
  "scanning": false,
  "descriptors": false
}
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ [Kmake generate BLOCKS=200
bitcoin-cli -datadir=1  -generate 200
{
  "address": "bcrt1q6hcax37jfu0wk72r0wmle039ps3628tnrwwwrk",
  "blocks": [
    "1d78da408249542f683293416cbf273ed5dd95ee11be6e68aa1264ed2f011975",
    "55c98c24b02a854b548589f60f9de1d7018fb19ab55b7d65e32e4e049705cf41",
    "43a54406ce7eb8bef09730acf18fa4b0752ba2fa7ea25d41602fa4f63646b7d7",
    "5b50d1f736e335a474e42cc3ce6c92f4e9cf9ed02a6510c1fcff457804001eff",
    "3b914d9ab7f6c1062f827331c0613a121143a423580a081da7f743317e96ea6d",
    "397b7be2d1f4e4b8f5a0c02eccc0b550c12c2916d8fd47e564f9d668645e0605",
    "3244b48c6aa1c55580adebe33dcfebd732e9b0293a68114d01ded6e90a953d21",
    "2e0e2bdffd8adfe427090854f65dc0bc2c75d9a9c8eb615827b2d2c8c644631c",
    "172065b54ef45dee8d65296a9438568abd8805f2824f1f8560288d2f7ad2d110",
    "501503ff6839ee4ad67fbc26111fd1e2bf650ea626db6397cb0e56617099f934",
    "633ff5e874ae53eef1a39021cde514467146f8855acba1e6a8323d6ef6ffb5df",
    "2b5c72225a47816d2ac64f48fd7aec5cfbebdc94b31c97935088c9ac2a0dbc56",
    "2cf8dd1f3013d4ada6204a9c256e5ca9e70f185497cbb655b64ddac8e35c9097",
    "32bb31ff804dd37b09fae88ddc50fada897cbb40275b3e8a3d678ef62596ad58",
    "05f713dea603ca534d30a0c39d293a8d9e41395f2517be7420c8f292e57e9377",
    "22cfaa5e2b5c2a0fadff097689cc8b20a20033bde47f79eae7bd2c04f7bffb22",
    "5577c8b832868e044d71d5c7d841059466e064651bffa716a5cf6eb2922f5a48",
    "0fb7a1e56c376501b62710f0deb8b1f0541be6cffa63e800e249234de8928c57",
    "036cbd0c20218fa8dbef52c1dd4b51a3e06cc1bceba798404da4c9f451d36772",
    "7fc119104a1724e980b4c98e0d0ee0901aeae986745d389b426485552908ffb8",
    "19f1275945e29f2cda0e85911943df5fd0be7d5c93a696535999d4909ad8ed44",
    "2ec5ca93043958d8c62b870d25ad495eb980ed196aae3b80962ace22f4b0ba99",
    "11932af4e432a515fb91375c2c4ee4873fb470b7a86621dcc043c57cb168b843",
    "527adfa289f47c1372196322870c8af0c11b5b331f85f6b2c4c4dfd012a67f9a",
    "7cea4e1fc9cb9b8418ab749e9ff06a3939218b7011c8d975dcb133bf6c976ae7",
    "524bc243de1d9634e343370ffdc79c5876f567ec69c58bb45a88053083f82828",
    "4e926e4f4877a8cc3ae18b1317393211fc8aafa63bdf46d3159b0b98200166f8",
    "79368472f2a22d36bc321cd0e5856b7c58d0a68b3345908834600fcdd6284b63",
    "68c517886850ed234142d5e9a97854061d373b1db65b786a31b1dec18aedb570",
    "78d2ad8eef9b7080859655f0f310a4605fe5136fc27c1415dc7a84f2e710e510",
    "0f1a3d195c14bad5d534da107afc88e075701faf77e0f80d6fd6d162bd09fb14",
    "1c3242a7128a65ad0058531eb551d170beea08300297577395b080b1543a5a50",
    "581562fabb90901b4dd31bce9830ce27cac3eadcf7e15894f0431b09ef81ef60",
    "02a17a20515fdc84b994b1beee5e890b46d3346cff9772b82b06c0e45ba0f496",
    "24dbdba67ac54f4a5996ab5e656a51ad9b1de4cbb90c4953346228e20ab9359c",
    "4e8f7982605331d6f218052df48a804423322ae2a170e4b5b6f63630da7491ab",
    "092703e7206db21114fd5c11f4e640b9bd802b94457c697cdfcd2e1243959e36",
    "3055cf8e641fad05b91171152bc5f77d5ba157f877932496b7369ea8e80be4b4",
    "40bea4bef45ad7bcd782c7e75545f369b08e334949a105129c5a868fddbccf13",
    "02dace0dd32070e83750dc9a4876d93bb88dac4d2cccc717b20babeef549dadc",
    "73e0e27587f9625b65385b9ba707d7c1556bf18ff8cc3d27f86bca3605041921",
    "4bfeed2e67a60546eec6aefea1bad81dbf2a600cc46e49aecae687c86524f601",
    "7f9bf4cee468ba87877cdda1ec6112a8daed24de048ef59fc619bf4a3db00aed",
    "1d5e3ceabe5965b417a6149508380d88d1130907ab80440911c08917dd3fc690",
    "194de65cfa075da5f9b882614b092741beacbfd7668bc2a16067bb1952def947",
    "714642366d55c6c79fe34109f4df05ea63ad7c926b454752628346671a8253b3",
    "7adf8f4288be269d892bdd7a5b4da1a18db5d032f68ec75fd538a6213d5314ab",
    "2983a6f3e2b9c8e572aa9a0d422aed0f31cdb1011b9043c74bac7ffc82d81112",
    "29b9b4671a34b6bcc8c254245886578344302619341701a9a639a6c1c0b94d97",
    "3d32d9d4a1219d186b9232da472f85ecfc2c46b964c41d4c7ec2159965894200",
    "6c11232f0415746cfe1213d4adfd1e3a55f02e10f2b4c377d0c5b3b7bd2f5b48",
    "6f4b45021768da54d4e24133f1a5fc43bf4a6998f363a93c4a1aeda48beb8827",
    "42ebc62453c189f5294d6fc76de41465c65e46e711bbbf94ac0280dd55a3cc06",
    "75504df274846c26cbd2a0beea376a459b504b6fb29d53309bcae2084f9fb975",
    "3557bcd344ea74d88919c7c492cc5ce376079f4c5ad53736c3414e823036fbe5",
    "334e0013c994afd6a0222f4a2740709f37cf4d459f69775e6b4d0f917902ae92",
    "41662c91750dbb45ee2747f64a1cd1af7f47d822ded36966d9488ee2f2995009",
    "13a9ca92a36d0633610af6f5558c31803ca8b9532d31f36b51ff03960a6d10b9",
    "582a8a7b7141cda5786b76f1bdee1804a720d6cd7e31e26fc9def30abb92b870",
    "71aa5b4272dd0e1214c22e4a6b1a4bc5db9adacd93dbc5e204e9d8b3df9b420e",
    "12c13bc60423de1bfa2acb74f37f7fda9401d9b77dabbdbf93a686b4394c67dd",
    "0ac3e2619e03f6a24b67f3d0823afde89321a15f519b4c31cfc655d184e6eebd",
    "07ece1278508dfb72c92f248458fa8836cfa43f6a027b0fee032f6e81201d953",
    "6939178c0643d2817b2605a4f0e7c0703de89a118038b403e9e77903d9676f2d",
    "4effc999edb492c525cc96c070705f4ebeab04a845eb489eb61749a868c45469",
    "7f1c9aa457ad5bf89f43c447a3da316459607d05e3e43708db787af5e0792f01",
    "6e39f56484ab664ca722147311a70d38704badba93d15b76e670985bdc43a32d",
    "200ea2229b325ca2a578406719d28dda2b361ef268a8a6f3e1a71f65518eb453",
    "4a6e11216aed1462d3eebc6721067422f1d6c60dd6f5b91fb90527a200360022",
    "399f85d45156db1404d11b7835972d01fb66f019758098497f60c847ee6af28a",
    "26d0ed4d673b89c11714603d7e3cdcf4cb21ebd41e2de2bea30175a52cee3ce1",
    "2379f7d8ab28e036a87459420f5205b90ea9c50e15b69fbec87c9bf714575b8b",
    "48ee849025a6a18c5cd991e13158372f0c60de6d477fb4a36b6c29b40cc12e0d",
    "529b2a5c2a911f75e19f03bf02e82c3a958af9d60affed63fa8b27facd7d7667",
    "2e4972f28d4bfb82603e973a131152ac80b1532192949434a127894aa36bb496",
    "416357a1264486a4562cf1ea56b3dd220108ab55129453bd0034231ad18bf8f6",
    "13eea3d1cfce2c526a5c7bd69fbf7c14654a0b2edc317aabe6f95605450d8163",
    "1d90205a1c59cb63d98e42e499282cfde26aee9359291e086b1a1bd947014f44",
    "319b1f02d384901466589e044eeb871a043dddeddffd0aedb04bfc4352d2141f",
    "05dee58f6ae6fd4f4ef9e1ffcd37fd367a2bc060a740f095e006410460c8db99",
    "5ee8227d303d0655ec2b814900780ed28cf8bb61397cfbc616768209259019bf",
    "3ef13ac18e30ae2d5d625263dfe6413729b0f1096d485c8059a0d41a5996c351",
    "34bf79fac20584b0ceb59898e4f754f71f470163db897c6db231473f6530f65a",
    "581abdf5e0044c9b23e39dc9e46ca520602352296dd789ec6de524af0c18c2e3",
    "54fa14b4ea525c3340ca8c441943f75dd921cfdb1fea5a84c57222c49fef002c",
    "7e1818d71bdb7deb17078d4f49d584606b5d1a8b154b9580e6c13afdd17c1c73",
    "73fc3b63ffa150f01b9741055d60f8538f4384dc84a072e580bdb87eabd7fe97",
    "0abb6cdd87e27b8d0457f73b5a5d28d8cc2c847399d7c773bd36bbc5c7877258",
    "1532f7581388810efa73a615bf12096d573da00752d6dde1c05d6e42275b82fe",
    "3c9bfe450463833c4db7268c32d67e33d59184077fdbdedaf8acb518d9a581f8",
    "4a6b99ffbe85648d09358ea135fd4c271ab14c6208c76656af11faf2527aa856",
    "52aaad6ada48ad627f565b28db94e65a59709e6909888b2bc4b26de2deabc7c9",
    "702c35125d9fc4f801d71fad19c3a93c066d7445621ef252ff43e52df82817ec",
    "68344c35ecb881e56c3738311a58a3b2a617294152ee4472bdeca789dd25b5f2",
    "6d44498b55f9a7f0b3a74e60f210e4e0e680a08b1f64ad3fd5e046f50e28e09f",
    "49692355e7d091f2fe7aba5dd5f6df883ea9f02f8148dd56ec9be107fbdd35cf",
    "5d78081838a3acd88f3ff95338134d98759e75f137391c8ba84fbd333b7f0802",
    "03e7e731ec6e20616e6d0dc5b61a936b797a066f967d7b262d0d7f0b3aa8632e",
    "71bb49af582faf4ebe7e21b0c00822a797e941a05c0ab3c91a0101a06b92ecc6",
    "67799e2e00173543da66a1f1941d8004aff2c7da2adf6b22f46458b3a1f30df0",
    "0c039eb8cfc59d424c7085f8ab75123ef50c322143e93aec943f689077329531",
    "1422f0a3e4bb97f9cf07a62216ae3536e13eee511660ca72a75cc484da2b7bb8",
    "11ec9e69c9b1b9241d092306dcc3cb8075907a75c34fb7eab1b05b23a86119ff",
    "1eaf9994fa48b02d336bde5081b8bd6b50dc81d48bc5d4aa40eb77abbf6b8b94",
    "5aeef84ec68e8263e033fc5164071723d8b01afb4f9f3689fee82f16f041d5b4",
    "68b4e6a0f759f30d215c77ccf7bfbf8901e55f9d845795120e07127e99b90bd7",
    "09c26f858f9ccd1950152403084a1d066c39f6003abcb101703b23d913fd0d2f",
    "3fb649e5910b8f3c7cd1f8ca6cf96b65276e053a880dc50a359dd18025006e23",
    "48e3440a534859e1f2b60597b30985e28dad02493c55c20c4f14bebe21476918",
    "165a812e29ee700b34768c679acf7eb6839987491df3902ca934ae5b422f59ee",
    "280cbb4d326248c9f168bcdadcfb097d05f4fb6468b4e9f46eca973f5d6e5f6d",
    "0e924ff976c38abbec60ab1eddc3ca1fe718ad6e83af97f2f95c1c76306b0a1d",
    "42bf50887e095294538cb341082a277ba559c97130a27cdc1b992f3adb2862d0",
    "1cacc956f9592a4e8ab99b47b75cb2776502c4271805f3c090e37643a862f696",
    "746ddd9ce2c931d10e51f44b279990a4b4d95e3e7c1dd762af83b583800999cb",
    "21c39cbbb156264ecdd442fdd18cbc312cc782d081f991d0e7f3d7967e82c1e3",
    "2d6d099cc88117c5d81feb30cb37223463d531f55aca256afe28eaf7cbfffcdb",
    "1390715393e1147fee1584b4a5bc72aeb39e31cd229981883afe48c2f627d64c",
    "7ee089268cd4d91296ab243ea514bf49fd131398ebd61481451c0f96f9ee467e",
    "322694b58d440769be0931b6d2079593cd4cee70d234a7e926c97ddee2333718",
    "42d0938dbbecd4c1f65e57a5045996509b0d93a04b43e94530b6415e3ef0256f",
    "0b6e003e52811d72ee5c7cd1af1a13066bcd0d492806a896f6d642c8c10e8d5f",
    "23f685a43f35039250523cc66c9dc2ccd1d7ea2f198ebda2b6ef341a557b74f5",
    "2b9e4f2597240aacdbdd8e82ff9e05c68d804b3e66373715f104fa7c1ae3040a",
    "135618886f69362c358cc40e6252db85430dd161b7b35728805e7fb20c2fbd7f",
    "3713a423999b3e92b04ec7b088890da92c0f8355ce9111d00732ba2f13a312aa",
    "0079f88204a95cebb2930de56cda294460d7a928d97cba19beb1ffefa3a1e4fa",
    "46c05198bc59b69d621f616e583ddd26605ea31220bfbc92d9cb4e1021087c34",
    "3c327e9b28098569e60aeeec3ad6e4cfd9118d966af23c8f6cc19de2ac0fb53b",
    "214fa9fcb0ba5d9c4461d32f0dac216743f8902cdc7ebb784b488837695aacb3",
    "75aa75731324118b6adceb3334324857d1a2773e123abfc237e691cb8fa4425e",
    "0d3671d5cf2dc4e4cde552fef88fda3bab397a9d667980a557292b2d58069d13",
    "6d30c7ac72c7d1f814633648428dc4add4b7e93438021999cd9fffaa4189c83c",
    "66af8bc656a6074f76412cb957e4d8b75f729ec1f83fc4a17a82d6558da1432b",
    "3eeaaa2ba754bc6f5bc1e1fe02110a83c33b673392fba8260b2dbd8939be73fe",
    "4522bb21eafb506b13e249b72a2f00c4f1c8e78af090b57d387066da916f6b66",
    "4a936141514b9bc9660cdddf4ad4e7be99b07f23e1e35f32e938c94d6ee0f497",
    "7ddd9b837088a7805e16e8157152626d5c444af341721aaff0870a06ef20b97b",
    "293b1c974cc169c349fd008ea0397641a072cb5373c6f33ed3c8e41119e92ff7",
    "58f101ad8f805ff71b883b77e0ce0efb1836dfa07080e2b5848255decb3caf66",
    "51f07f2e48a9fe463aaecc9c2655d0755f14af6370379221c47c6b06093ca957",
    "3682940110acb72d279ee9f4bc433252a909043092519d7495708edcab0b601e",
    "6e9d2cf6de69f0cd084953325c32b66b9f0f09db16239c2a1522f0e657ae715a",
    "22dcc0b00e3c4c86d13b38fd0421c9f87e6b46ea33860431f0d91726dd285c17",
    "791707f77ba56b7e8e5472aea82108b64cc805c04f801bc13796ef665f2882a3",
    "33aa9bbd450c8b8aad40a2dc600b1db0ff98d831945b5fae420ad546185528a7",
    "693db9f76b3afa5729e868cc09d6fb90209f81c5dd7c2a75728528e669ab07a1",
    "237cd80d5713d27aa092ed9825bbc6612177dc419fe4d47e01fd15422ac736ab",
    "4e35ecddf147ddccd76657b9da668721f5a4123976c0c0efdd51d570aa68407c",
    "00cfd35e72e1bcd3e4bde397c194bc2ffa44506c339bf0dff42b164665ff6abc",
    "52a262a282910e2a606b184167a08a9a7fa73d04a058000a2d59ca5a9c94331e",
    "51236201e0f36209f44723dd016e9de7874364816ec45cfe8e5f12a8f824b7e5",
    "0750a3f7cfa82eaf344a9066650ea6c8a9f80b936c2ae407f3c25ed481cba4e9",
    "371ad3157d622607b8a012c4c67830e8b231fcb3cb2228b675a5c977466749b3",
    "65d3207544406e6cb8c7ee41fb83dc37d1a69f6d8f2ac18fd46328b72df3a82b",
    "2731abf385149814d87e4ab3a715a483ea23661edc3eefbbddfdc39260c77f13",
    "52fd98ec07a2ddd0349073adf4aee5d73875a30268dcda09d3d1fc2d0554937d",
    "6e3d872f08c577a6bf6d6a8b8c69709dfe83c98a572b3a857f548393bc9d4d61",
    "3236f8e0406d9cf92d27f29f48aaeebae61a901aefdad3d5a093722b3b49b8db",
    "71a8446124df049c9c4d07d8c06ccf0026ee9a873c2fa6da2d507b7b3872a59c",
    "4d210514c8985dc034047df4a7bc913667a75d8df6a0371e3bbe65d6b604a05c",
    "557211ae7ffe63f8e6b4819a520ca05a0558f5deaa0b27a5f7c10336253a8ee3",
    "3197ac3f77ac8f46717da2019c7191eff0c3147edc758ca9c4c0450cd6544017",
    "2801b0b33457b2b8a771002f4a04bb2ad52bfe2d6fa0d3e45bc80e14c1c4e92a",
    "7cea3dc586b09227d004c288243460159ebf4e96402de4f5f66983cbc9f7c0aa",
    "33b9081767f3f507b70427de1f2a1eafed0d1b05270193af0db4cc2392013516",
    "67c873e59a886cdc4d5981a03285278a606c2c913a60ee0b9dd3f5fd3a0ef8ad",
    "1668f5504cb4076f9c4b5a625d4cd1149ba885460913d8921c430086f5a762fc",
    "3edc1b63669ed33f75c6caf665af52970cfbfa3058a37ee52e7b180b61857ac2",
    "2349df4a140db45ce28190a707c875ae641cb27d3975e7425de8f3b1b6dc79c3",
    "47fc2efeba068dc7f4b43d4725a1d2fa6503a1e8780ae01b58a722e57c744f27",
    "4066e82a5c542808f20de24b026e73e3c7cf69395b8a024631e0a2faf5669cbb",
    "3a092b2a3c3882b0a7778511dd8a40d9ed729a374a387c22ec089b5e8875cb50",
    "444a0ca29e5ab4e1e80826d86439ba1efbc4e586cf137aeb601379990b9eee5a",
    "3531538bdb20c6b8318c7e9d3ea93929eb763b680c4f087908eb056e229f5db7",
    "050f17d98a8012169b3218f520bfa4ba2cce6dfb5e231639efb462cc099dd74d",
    "5459d8664a6297c548c7102501a88401cb7318cf6b2af548e609e7dfb8c5b985",
    "53bcc61fdd732ebe0b4da5c99dd2181f45566450c35b8b3f8e3ce2c11ed24cd9",
    "784326f64431818c49a4f8c15715bffd231093b7df741628b41a4509d6e3b97e",
    "7025b8c2e09a08405bae06f1710ae99511973995a7d7fc0e0d38b799cb1f3c82",
    "035e370ade15ad4c4c4764ecdbcd7719cd4c9c55ead07c2efd15aefc275f64cb",
    "1294d8d5b902b523b91987ecd9b2567c103e464a8a2003cb004fd45858d0368b",
    "799411527298d4301fead9249955367948e6dd723ea438af0b7b67c41fc4b76b",
    "431717adf7316261a915eb3b42fb40d11bc45dff98ef11c85d2203463a57d502",
    "1689e44125c5b9ec293cf43aba8f3758fdb80a2206aaab947c81e068297672b3",
    "0c7fcbceab1473071365871bb94c5e92144fd75b87d89e3af74cb84e0af017c6",
    "7b8a4b05c4edb8aac13cf2aa3de765525aa645460db4d5182c059ee6129c7015",
    "7c08460c861c8c0aaec23abe76ed3edf29afa304e7fe058d60042b842c6da1d9",
    "17774c298de551ae317a7ddb74465d65a1d0dc0c60a351540130027c1bae3f8a",
    "5a490ebb66e3da89d3bf24ae786bcc11ec45044f42ab6570e181b067d44ff304",
    "1f450c095264a676d6c53380418de7fef18cfcec4bbb3bf35900f9c7c868bc8c",
    "523b6f6be7089ec31fd31c6703586f3a2540d45b9f392ca78bc78bd4497c0e6f",
    "67b1b11f471be602fd01de8e45b1e5640097fcba200859f11923f516bffb678d",
    "737f1dedf87031d81c36646402f978f8c15d7c608fdae1441973e45d6af2e786",
    "54e9caba2a8153d16daa26581eef21e60af8a146ab118e69de31a9793076db56",
    "74200b6b01c893585b226af4ec60c683f44be02e00282def42f585e628d65da7",
    "280fa2ede1ea0da960f62a7d44e83b0088dbe58c693d03d2607f47afd3b92c4a",
    "4aad0bb47a87abb2e9f0d75a839c6e17db239d7d17ab082e19ec0268827cb52d",
    "1413ca031ebce4aaa501a6268f472f3b1ec7d8d21617b7f8a755dd8e5cdf6a05",
    "017bf29f599fc0685fe3e9946c2d94eee51408a44284f2afac79898c920be40c"
  ]
}
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ make generate BLOCKS=200bitcoin-cli -datadir=1 getwalletinfo 
[A[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ bitcoin-cli -datadir=1 getwalletinf[Ko
{
  "walletname": "test1",
  "walletversion": 169900,
  "format": "bdb",
  "balance": 5000.00000000,
  "unconfirmed_balance": 0.00000000,
  "immature_balance": 3725.00000000,
  "txcount": 200,
  "keypoololdest": 1659000272,
  "keypoolsize": 999,
  "hdseedid": "477d9c1bc4de01a1cdfbc95c719f68ad6849409a",
  "keypoolsize_hd_internal": 1000,
  "paytxfee": 0.00000000,
  "private_keys_enabled": true,
  "avoid_reuse": false,
  "scanning": false,
  "descriptors": false
}
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ [Kbitcoin-cli -datadir=1  sendtoaddress
s 2N5czXHSEFronnYvMHUhSinQW8jjp7UjRtu 10[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[1P[44@bcrt1qdejfeswfskz6a9vx8pqa4z77rjtzxenu6zn6te
error code: -6
error message:
Fee estimation failed. Fallbackfee is disabled. Wait a few blocks or enable -fallbackfee.
[32;32mtester@6620a3d170ec[00m [01;34m~/bitcoin-testnet-box[00m$ [Kexit
exit
]0;jx05lan@jx05lan-VirtualBox: ~[01;32mjx05lan@jx05lan-VirtualBox[00m:[01;34m~[00m$ exit
exit

Script done on 2022-07-28 17:26:49+08:00 [COMMAND_EXIT_CODE="6"]
