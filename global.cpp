#include "global.h"
QString cloud_url_prefix="";
// 函数的实现（定义），只放在一个 .cpp 文件里
QString truncateText(const QString &str, int maxLength)
{
    if (str.length() <= maxLength)
        return str;
    else
        return str.left(maxLength) + "...";
}
int nextSongId = 1;
