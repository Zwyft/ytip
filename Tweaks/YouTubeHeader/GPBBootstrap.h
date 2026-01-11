#import <stdint.h>

#ifndef GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS
#define GPBOBJC_SKIP_MESSAGE_TEXTFORMAT_EXTRAS 0
#endif

#if !__has_feature(objc_fixed_enum)
#error All supported Xcode versions should support objc_fixed_enum.
#endif

#if (defined(__cplusplus) && __cplusplus && __cplusplus < 201103L)
#define GPB_ENUM(X)   \
  enum X : int32_t X; \
  enum X : int32_t
#else
#define GPB_ENUM(X) NS_ENUM(int32_t, X)
#endif

#define GPB_ENUM_FWD_DECLARE(X) enum X : int32_t

#if !defined(DEBUG)
#define GPB_INLINE static __inline__ __attribute__((always_inline))
#else
#define GPB_INLINE static __inline__
#endif

#ifndef GPB_UNSAFE_UNRETAINED
#if __has_feature(objc_arc)
#define GPB_UNSAFE_UNRETAINED __unsafe_unretained
#else
#define GPB_UNSAFE_UNRETAINED
#endif
#endif

#ifndef GPB_DEPRECATED
#define GPB_DEPRECATED __attribute__((deprecated))
#endif

#ifndef GPB_DEPRECATED_MSG
#if __has_extension(attribute_deprecated_with_message)
#define GPB_DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
#else
#define GPB_DEPRECATED_MSG(msg) __attribute__((deprecated))
#endif
#endif

#define GPB_METHOD_FAMILY_NONE __attribute__((objc_method_family(none)))

#ifndef GPB_FINAL
#define GPB_FINAL __attribute__((objc_subclassing_restricted))
#endif

#define GOOGLE_PROTOBUF_OBJC_VERSION 30007

#define GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION 30001

#define GOOGLE_PROTOBUF_OBJC_GEN_VERSION 30001
