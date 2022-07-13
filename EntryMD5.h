//
//  EntryMD5.h
//
//
//  Created by github.com/foolsparadise on 2018/6/2.
//

#ifndef EntryMD5_H
#define EntryMD5_H

#ifdef __cplusplus
extern "C"
{
#endif

    /*
     this is only lower case 32bit
     32位小写
     usage:
     char keyValue[64];
     memset(keyValue,0,sizeof(keyValue));
     EntryMD5("123456",keyValue);
     printf("%s", keyValue); // so, md5 123456 = "e10adc3949ba59abbe56e057f20f883e"
     */
    void EntryMD5(const char *from, char *to);

#ifdef __cplusplus
}
#endif

#endif
