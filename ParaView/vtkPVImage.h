/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPVImage.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 1998-1999 Kitware Inc. 469 Clifton Corporate Parkway,
Clifton Park, NY, 12065, USA.

All rights reserved. No part of this software may be reproduced, distributed,
or modified, in any form or by any means, without permission in writing from
Kitware Inc.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

=========================================================================*/

#ifndef __vtkPVImage_h
#define __vtkPVImage_h

#include "vtkKWWidget.h"
#include "vtkProp.h"
#include "vtkImageData.h"
#include "vtkOutlineSource.h"
#include "vtkKWLabel.h"
#include "vtkPolyDataMapper.h"

class vtkPVComposite;

class VTK_EXPORT vtkPVImage : public vtkKWWidget
{
public:
  static vtkPVImage* New();
  vtkTypeMacro(vtkPVImage,vtkKWWidget);
  
  void Create(vtkKWApplication *app, char *args);

  vtkProp* GetProp();

  vtkSetObjectMacro(Image, vtkImageData);
  vtkGetObjectMacro(Image, vtkImageData);
  
  void SetComposite(vtkPVComposite *comp);
  
protected:
  vtkPVImage();
  ~vtkPVImage();
  vtkPVImage(const vtkPVImage&) {};
  void operator=(const vtkPVImage&) {};

  vtkKWLabel *Label;
  vtkImageData *Image;
  vtkOutlineSource *Outline;
  vtkPolyDataMapper *Mapper;
  vtkActor *Actor;
  vtkPVComposite *Comp;
};

#endif
