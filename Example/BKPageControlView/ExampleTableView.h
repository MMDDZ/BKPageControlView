//
//  ExampleTableView.h
//  BKPageControlViewDemo
//
//  Created by zhaolin on 2019/7/8.
//  Copyright © 2019 BIKE. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ExampleTableView : UITableView

@property (nonatomic,copy) void (^hitTestCallBack)(CGPoint point);

@end

NS_ASSUME_NONNULL_END
