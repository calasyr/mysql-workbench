/* 
 * Copyright (c) 2008, 2015, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#import <Cocoa/Cocoa.h>
#include "mdc_canvas_view_macosx.h"

@protocol CanvasViewerDelegate

- (BOOL)canvasMouseDown:(mdc::MouseButton)button
               location:(NSPoint)pos
                  state:(mdc::EventState)state;
- (BOOL)canvasMouseDoubleClick:(mdc::MouseButton)button
                      location:(NSPoint)pos
                         state:(mdc::EventState)state;
- (BOOL)canvasMouseUp:(mdc::MouseButton)button
             location:(NSPoint)pos
                state:(mdc::EventState)state;
- (BOOL)canvasMouseMoved:(NSPoint)pos
                   state:(mdc::EventState)state;

- (BOOL)canvasKeyDown:(mdc::KeyInfo)key state:(mdc::EventState)state;
- (BOOL)canvasKeyUp:(mdc::KeyInfo)key state:(mdc::EventState)state;

- (NSDragOperation)canvasDraggingEntered:(id < NSDraggingInfo >)sender;
- (NSDragOperation)draggingUpdated: (id <NSDraggingInfo>)sender;
- (BOOL)canvasPerformDragOperation:(id < NSDraggingInfo >)sender;

@end

@interface MCanvasViewer : NSView
{
  mdc::QuartzCanvasView *_view;
  id<CanvasViewerDelegate> _delegate;
  NSCursor *_cursor;
  int _buttonState;
  NSTrackingArea *_trackingArea;
  
  BOOL _firstResponder;
}

//- (void)setupOpenGL;
- (void)setupQuartz;

@property (readonly) mdc::CanvasView *canvas;

- (void)setCursor:(NSCursor*)cursor;

@property (assign) id delegate;

- (void)scrollToPoint:(NSPoint)offset;
@property (readonly) NSRect documentRect;
@property (readonly) NSRect documentVisibleRect;

@end

