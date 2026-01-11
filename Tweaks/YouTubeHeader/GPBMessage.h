#import <Foundation/Foundation.h>
#import "GPBBootstrap.h"
#import "GPBExtensionRegistry.h"

@class GPBDescriptor;
@class GPBCodedInputStream;
@class GPBCodedOutputStream;
@class GPBExtensionDescriptor;
@class GPBFieldDescriptor;
@class GPBUnknownFieldSet;

NS_ASSUME_NONNULL_BEGIN

CF_EXTERN_C_BEGIN

extern NSString *const GPBMessageErrorDomain;

typedef NS_ENUM(NSInteger, GPBMessageErrorCode) {
  GPBMessageErrorCodeOther = -100,
  GPBMessageErrorCodeMissingRequiredField = -101,
};

extern NSString *const GPBErrorReasonKey;
extern NSString *const GPBMessageExceptionMessageTooLarge;

CF_EXTERN_C_END

@interface GPBMessage : NSObject <NSSecureCoding, NSCopying>
@property(nonatomic, copy, nullable) GPBUnknownFieldSet *unknownFields;
@property(nonatomic, readonly, getter=isInitialized) BOOL initialized;
+ (instancetype)message;
+ (nullable instancetype)parseFromData:(NSData *)data error:(NSError **)errorPtr;
+ (nullable instancetype)parseFromData:(NSData *)data extensionRegistry:(nullable id<GPBExtensionRegistry>)extensionRegistry error:(NSError **)errorPtr;
+ (nullable instancetype)parseFromCodedInputStream:(GPBCodedInputStream *)input extensionRegistry: (nullable id<GPBExtensionRegistry>)extensionRegistry error:(NSError **)errorPtr;
+ (nullable instancetype)parseDelimitedFromCodedInputStream:(GPBCodedInputStream *)input extensionRegistry: (nullable id<GPBExtensionRegistry>)extensionRegistry error:(NSError **)errorPtr;
- (nullable instancetype)initWithData:(NSData *)data error:(NSError **)errorPtr;
- (nullable instancetype)initWithData:(NSData *)data extensionRegistry:(nullable id<GPBExtensionRegistry>)extensionRegistry error:(NSError **)errorPtr;
- (nullable instancetype)initWithCodedInputStream:(GPBCodedInputStream *)input extensionRegistry: (nullable id<GPBExtensionRegistry>)extensionRegistry error:(NSError **)errorPtr;
- (void)mergeFromData:(NSData *)data extensionRegistry:(nullable id<GPBExtensionRegistry>)extensionRegistry __attribute__((deprecated("Use -mergeFromData:extensionRegistry:error: instead, especaily if calling from Swift.")));
- (BOOL)mergeFromData:(NSData *)data extensionRegistry:(nullable id<GPBExtensionRegistry>)extensionRegistry error:(NSError **)errorPtr;
- (void)mergeFrom:(GPBMessage *)other;
- (void)writeToCodedOutputStream:(GPBCodedOutputStream *)output;
- (void)writeToOutputStream:(NSOutputStream *)output;
- (void)writeDelimitedToCodedOutputStream:(GPBCodedOutputStream *)output;
- (void)writeDelimitedToOutputStream:(NSOutputStream *)output;
- (nullable NSData *)data;
- (NSData *)delimitedData;
- (size_t)serializedSize;
+ (GPBDescriptor *)descriptor;
- (GPBDescriptor *)descriptor;
- (NSArray *)extensionsCurrentlySet;
- (BOOL)hasExtension:(GPBExtensionDescriptor *)extension;
- (nullable id)getExtension:(GPBExtensionDescriptor *)extension;
- (void)setExtension:(GPBExtensionDescriptor *)extension value:(nullable id)value;
- (void)addExtension:(GPBExtensionDescriptor *)extension value:(id)value;
- (void)setExtension:(GPBExtensionDescriptor *)extension index:(NSUInteger)index value:(id)value;
- (void)clearExtension:(GPBExtensionDescriptor *)extension;
- (void)clear;
@end

NS_ASSUME_NONNULL_END
