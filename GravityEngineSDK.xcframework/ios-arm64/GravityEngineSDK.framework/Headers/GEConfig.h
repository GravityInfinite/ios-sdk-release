#import <Foundation/Foundation.h>

#if __has_include(<GravityEngineSDK/GEConstant.h>)
#import <GravityEngineSDK/GEConstant.h>
#else
#import "GEConstant.h"
#endif

#if __has_include(<GravityEngineSDK/GESecurityPolicy.h>)
#import <GravityEngineSDK/GESecurityPolicy.h>
#else
#import "GESecurityPolicy.h"
#endif

#if TARGET_OS_IOS
#if __has_include(<GravityEngineSDK/GESecretKey.h>)
#import <GravityEngineSDK/GESecretKey.h>
#else
#import "GESecretKey.h"
#endif
#endif



NS_ASSUME_NONNULL_BEGIN



@interface GEConfig:NSObject <NSCopying>
/**
 Set automatic burying type
 */
@property (assign, nonatomic) GravityEngineAutoTrackEventType autoTrackEventType;
/**
 Network environment for data transmission
 */
@property (assign, nonatomic) GravityNetworkType networkTypePolicy;
/**
 Data upload interval
 */
@property (nonatomic, strong) NSNumber *uploadInterval;
/**
 When there is data to upload, when the number of data cache reaches the uploadsize, upload the data immediately
 */
@property (nonatomic, strong) NSNumber *uploadSize;
/**
 Event blacklist, event names that are not counted are added here
 */
@property (strong, nonatomic) NSArray *disableEvents;
/**
 The maximum number of cached events, the default is 10000, the minimum is 5000
 */
@property (class,  nonatomic) NSInteger maxNumEvents DEPRECATED_MSG_ATTRIBUTE("Please config GEConfigInfo in main info.plist");
/**
 Data cache expiration time, the default is 10 days, the longest is 10 days
 */
@property (class,  nonatomic) NSInteger expirationDays DEPRECATED_MSG_ATTRIBUTE("Please config GEConfigInfo in main info.plist");
/**
 appid
 */
@property (atomic, copy) NSString *appid;
/**
 instance Token
 */
@property (atomic, copy) NSString *(^getInstanceName)(void);
/**
 Server URL
 */
@property (atomic, copy) NSString *configureURL;
/**
 Gravity AccessToken
 */
@property (nonatomic, copy) NSString *accessToken;

/**
 Initialize and configure background self-starting events
 YES: Collect background self-starting events
 NO: Do not collect background self-starting events
 */
@property (nonatomic, assign) BOOL trackRelaunchedInBackgroundEvents;
/**
 Debug Mode
*/
@property (nonatomic, assign) GravityEngineDebugMode debugMode;

/**
app launchOptions
*/
@property (nonatomic, copy) NSDictionary *launchOptions;

/**
 Initialize and configure the certificate verification policy
*/
@property (nonatomic, strong) GESecurityPolicy *securityPolicy;

/**
 Set default time zone
  You can use this time zone to compare the offset of the current time zone and the default time zone
*/
@property (nonatomic, strong) NSTimeZone *defaultTimeZone;

/**
 instance name
*/
@property (nonatomic, copy) NSString *name;

+ (GEConfig *)defaultGEConfig;
- (void)setNetworkType:(GravityEngineNetworkType)type;


/// enable encryption
@property (nonatomic, assign) BOOL enableEncrypt;


/// 是否设置为GDPR区域，默认为NO关闭
@property (nonatomic, assign) BOOL isGDPRArea;

/// 如果您的应用需要符合《儿童在线隐私权保护法》(COPPA) 规定，设置 isCoppaEnabled = YES,，默认为NO关闭
@property (nonatomic, assign) BOOL isCoppaEnabled;

///如果您的应用会定向到不满 13 周岁的儿童，则需要将其标记为儿童应用 (Kids App)，设置 isKidsAppEnabled = YES，默认为NO关闭
@property (nonatomic, assign) BOOL isKidsAppEnabled;


///前台会话阀值（频繁切换前后台，AppEnd时间会很小，可以设置这个值忽略这种操作）,当AppEnd发生时，事件少于设置的time，会忽略计时
@property (nonatomic, assign) int foregroundSessionThreshold;
#if TARGET_OS_IOS
/// Get local key configuration
@property (nonatomic, strong) GESecretKey *secretKey;
#endif

/// instance token
- (NSString *)getMapInstanceToken;

-(BOOL)isCanReportIDs;
@end
NS_ASSUME_NONNULL_END
