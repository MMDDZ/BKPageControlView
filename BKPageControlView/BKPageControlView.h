//
//  BKPageControlView.h
//
//  Created on 16/2/2.
//  Copyright © 2016年 BIKE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BKPageControlViewController.h"
#import "BKPageControlMenuView.h"
@class BKPageControlView;

@protocol BKPageControlViewDelegate <NSObject>

@optional

/**
 准备离开index

 @param leaveIndex 离开的index
 */
-(void)sliderView:(BKPageControlView*)sliderView willLeaveIndex:(NSUInteger)leaveIndex;

/**
 切换index中

 @param sliderView BKPageControlView
 @param switchingIndex 切换中的index
 @param leavingIndex 离开中的index
 @param percentage 百分比
 */
-(void)sliderView:(BKPageControlView *)sliderView switchingIndex:(NSUInteger)switchingIndex leavingIndex:(NSUInteger)leavingIndex percentage:(CGFloat)percentage;

/**
 切换index

 @param sliderView BKPageControlView
 @param switchIndex 切换的index
 @param leaveIndex 离开的index
 */
-(void)sliderView:(BKPageControlView*)sliderView switchIndex:(NSUInteger)switchIndex leaveIndex:(NSUInteger)leaveIndex;

#pragma mark - 主视图滑动代理

/**
 滑动主视图
 
 @param sliderView BKPageControlView
 @param bgScrollView 主视图
 */
-(void)sliderView:(BKPageControlView*)sliderView didScrollBgScrollView:(UIScrollView*)bgScrollView;

/**
 开始滑动主视图
 
 @param sliderView BKPageControlView
 @param bgScrollView 主视图
 */
-(void)sliderView:(BKPageControlView*)sliderView willBeginDraggingBgScrollView:(UIScrollView*)bgScrollView;

/**
 主视图惯性结束
 
 @param sliderView BKPageControlView
 @param bgScrollView 主视图
 */
-(void)sliderView:(BKPageControlView*)sliderView didEndDeceleratingBgScrollView:(UIScrollView*)bgScrollView;

/**
 主视图停止拖拽
 
 @param sliderView BKPageControlView
 @param bgScrollView 主视图
 */
-(void)sliderView:(BKPageControlView*)sliderView didEndDraggingBgScrollView:(UIScrollView*)bgScrollView willDecelerate:(BOOL)decelerate;

#pragma mark - 导航

/**
 设置导航视图中menu上的icon和选中的icon
 
 @param menu menu
 @param iconImageView icon
 @param selectIconImageView 选中的icon
 @param index 索引
 */
-(void)sliderView:(BKPageControlView *)sliderView menu:(BKPageControlMenu*)menu settingIconImageView:(UIImageView*)iconImageView selectIconImageView:(UIImageView*)selectIconImageView atIndex:(NSUInteger)index;

@end

@interface BKPageControlView : UIView

#pragma mark - 初始化方法

/**
 初始化方法

 @param frame 坐标大小
 @param delegate 代理
 @param childControllers 展示的子控制器数组 (子控制器的标题就是目录中的标题)
 @param superVC 父视图 (用于保存子控制器)
 @return BKPageControlView
 */
-(instancetype)initWithFrame:(CGRect)frame delegate:(id<BKPageControlViewDelegate>)delegate childControllers:(NSArray<BKPageControlViewController*>*)childControllers superVC:(UIViewController*)superVC;

/**
 代理
 */
@property (nonatomic,weak) id<BKPageControlViewDelegate> delegate;
/**
 展示的子控制器数组 (子控制器的标题就是目录中的标题)
 */
@property (nonatomic,copy) NSArray<BKPageControlViewController*> * childControllers;
/**
 父视图 (用于保存展示的子控制器)
 */
@property (nonatomic,weak,readonly) UIViewController * superVC;

/**
 选中索引 从0开始
 (selectIndex >= [viewControllers count] - 1 时 selectIndex = [viewControllers count] - 1)
 */
@property (nonatomic,assign) NSUInteger selectIndex;

#pragma mark - 主视图

/**
 主视图（竖直滚动）
 */
@property (nonatomic,strong) UIScrollView * bgScrollView;

#pragma mark - 第二级视图

/**
 头视图
 */
@property (nonatomic,strong) UIView * headerView;

/**
 内容视图(包含导航和内容)
 */
@property (nonatomic,strong) UIView * contentView;

#pragma mark - 导航视图（第三级）

/**
 导航视图
 */
@property (nonatomic,strong) BKPageControlMenuView * menuView;

#pragma mark - 内容视图（第三级）

/**
 详情内容视图
 */
@property (nonatomic,strong) UICollectionView * collectionView;
/**
 详情内容视图左右插入量 默认0
 */
@property (nonatomic,assign) CGFloat contentLrInsets;

/**
 用自定义的滑动手势代替系统的滑动手势(因项目需求需要嵌套两层sliderView，并且两层都需要使用左右滑动，所以这个属性诞生了)
 */
@property (nonatomic,assign) BOOL useCsPanGestureOnCollectionView;

/**
 自定义滑动手势
 */
@property (nonatomic,strong,readonly) UIPanGestureRecognizer * csCollectionViewPanGesture;

@end



