/*
* Copyright 2006 Sony Computer Entertainment Inc.
*
* Licensed under the MIT Open Source License, for details please see license.txt or the website
* http://www.opensource.org/licenses/mit-license.php
*
*/ 

#ifndef __dom141Cg_sampler1D_h__
#define __dom141Cg_sampler1D_h__

#include <dae/daeDocument.h>
#include <1.4/dom/domTypes.h>
#include <1.4/dom/domElements.h>

#include <1.4/dom/domFx_sampler1D_common.h>

class DAE;
namespace ColladaDOM141 {

class domCg_sampler1D_complexType  : public domFx_sampler1D_common_complexType
{

protected:
	/**
	 * Constructor
	 */
	domCg_sampler1D_complexType(DAE& dae, daeElement* elt) : domFx_sampler1D_common_complexType(dae, elt) {}
	/**
	 * Destructor
	 */
	virtual ~domCg_sampler1D_complexType() {}
	/**
	 * Overloaded assignment operator
	 */
	virtual domCg_sampler1D_complexType &operator=( const domCg_sampler1D_complexType &cpy ) { (void)cpy; return *this; }
};

/**
 * An element of type domCg_sampler1D_complexType.
 */
class domCg_sampler1D : public daeElement, public domCg_sampler1D_complexType
{
public:
	virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::CG_SAMPLER1D; }
	static daeInt ID() { return 127; }
	virtual daeInt typeID() const { return ID(); }
protected:
	/**
	 * Constructor
	 */
	domCg_sampler1D(DAE& dae) : daeElement(dae), domCg_sampler1D_complexType(dae, this) {}
	/**
	 * Destructor
	 */
	virtual ~domCg_sampler1D() {}
	/**
	 * Overloaded assignment operator
	 */
	virtual domCg_sampler1D &operator=( const domCg_sampler1D &cpy ) { (void)cpy; return *this; }

public: // STATIC METHODS
	/**
	 * Creates an instance of this class and returns a daeElementRef referencing it.
	 * @return a daeElementRef referencing an instance of this object.
	 */
	static DLLSPEC daeElementRef create(DAE& dae);
	/**
	 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
	 * If a daeMetaElement already exists it will return that instead of creating a new one. 
	 * @return A daeMetaElement describing this COLLADA element.
	 */
	static DLLSPEC daeMetaElement* registerElement(DAE& dae);
};


} // ColladaDOM141
#endif
