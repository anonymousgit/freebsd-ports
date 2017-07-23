--- libcork/include/libcork/config/linux.h.orig	2017-07-20 16:43:38 UTC
+++ libcork/include/libcork/config/linux.h
@@ -15,7 +15,7 @@
  * Endianness
  */
 
-#include <endian.h>
+#include <sys/endian.h>
 
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define CORK_CONFIG_IS_BIG_ENDIAN      1
