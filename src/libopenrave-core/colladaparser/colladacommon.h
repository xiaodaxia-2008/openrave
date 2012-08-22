// -*- coding: utf-8 -*-
// Copyright (C) 2006-2012 Rosen Diankov <rosen.diankov@gmail.com>, Stefan Ulbrich, Gustavo Rodriguez
//
// This file is part of OpenRAVE.
// OpenRAVE is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
/** \file colladacommon.h
    \brief Common external definitions for the collada reader/writer
 */
#ifndef OPENRAVE_COLLADA_COMMON_H
#define OPENRAVE_COLLADA_COMMON_H

#include "../ravep.h"

#ifdef OPENRAVE_COLLADA_SUPPORT

#define COLLADA_DOM_NAMESPACE // collada-dom 2.4
namespace ColladaDOM150 {} // declare in case earlier versions are used

#include <dae.h>
#include <dae/daeErrorHandler.h>
#include <dae/domAny.h>
#include <dae/daeDocument.h>
#include <1.5/dom/domCOLLADA.h>
#include <1.5/dom/domConstants.h>
#include <1.5/dom/domTriangles.h>
#include <1.5/dom/domTypes.h>
#include <1.5/dom/domElements.h>
#include <boost/lexical_cast.hpp>

class ColladaReader;
class ColladaWriter;

/// \brief holds all information required to describe the collada references to the loaded body
class ColladaXMLReadable : public XMLReadable
{
public:
    static std::string GetXMLIdStatic() {
        return string("__collada__");
    }

    /// \brief sid bindings for kinematics, physics, and visual
    struct Binding
    {
        Binding() : index(-1) {
        }
        Binding(const std::string& kmodel, const std::string& pmodel, const std::string& vmodel) : kmodel(kmodel), pmodel(pmodel), vmodel(vmodel), index(-1) {
        }
        std::string kmodel, pmodel, vmodel;
        int index; ///< for _bindingLinkSIDs, it is the index inside the _bindingModelURLs vector
    };

    /// \brief sid bindings for kinematics, physics, and visual
    struct AxisBinding
    {
        AxisBinding() {
        }
        AxisBinding(const std::string& kmodelaxissidref, const std::string& nodesid) : kmodelaxissidref(kmodelaxissidref), nodesid(nodesid) {
        }
        std::string kmodelaxissidref;
        std::string nodesid;
    };

    /// \brief sid bindings for kinematics, physics, and visual
    struct ModelBinding
    {
        ModelBinding() {
        }
        ModelBinding(const std::string& kmodel, const std::string& pmodel, const std::string& vmodel) : kmodel(kmodel), pmodel(pmodel), vmodel(vmodel) {
        }
        std::string kmodel; ///< kmodel is a SIDREF to the instance_kinematics_model that will later be used in bind_kinematics_model
        std::string pmodel;
        std::string vmodel; ///< vmodel is the node url without any translations/rotations
        std::string ikmodelsidref;
    };

    ColladaXMLReadable() : XMLReadable(GetXMLIdStatic()) {
    }

    std::string _articulated_systemURL; ///< urls of the articulated_system, physics_model, and visual node
    std::vector<ModelBinding> _bindingModelURLs;
    std::vector<AxisBinding> _bindingAxesSIDs;
    std::vector<Binding> _bindingLinkSIDs; ///< link bindings, SID for link, rigidbody, but URL for vmodel (node)
};

typedef boost::shared_ptr<ColladaXMLReadable> ColladaXMLReadablePtr;

// register for typeof (MSVC only)
#ifdef RAVE_REGISTER_BOOST
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
BOOST_TYPEOF_REGISTER_TYPE(ColladaXMLReadable::Binding)
#endif


bool RaveParseColladaURI(EnvironmentBasePtr penv, const std::string& uri,const AttributesList& atts);
bool RaveParseColladaFile(EnvironmentBasePtr penv, const std::string& filename,const AttributesList& atts);
bool RaveParseColladaFile(EnvironmentBasePtr penv, KinBodyPtr& ppbody, const std::string& filename,const AttributesList& atts);
bool RaveParseColladaFile(EnvironmentBasePtr penv, RobotBasePtr& pprobot, const std::string& filename,const AttributesList& atts);
bool RaveParseColladaData(EnvironmentBasePtr penv, const std::string& data,const AttributesList& atts);
bool RaveParseColladaData(EnvironmentBasePtr penv, KinBodyPtr& ppbody, const std::string& data,const AttributesList& atts);
bool RaveParseColladaData(EnvironmentBasePtr penv, RobotBasePtr& pprobot, const std::string& data,const AttributesList& atts);

void RaveWriteColladaFile(EnvironmentBasePtr penv, const std::string& filename,const AttributesList& atts);
void RaveWriteColladaFile(KinBodyPtr pbody, const std::string& filename,const AttributesList& atts);
void RaveWriteColladaFile(const std::list<KinBodyPtr>& listbodies, const std::string& filename,const AttributesList& atts);

#else

inline bool RaveParseColladaURI(EnvironmentBasePtr penv, const std::string& uri,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
    return false;
}

inline bool RaveParseColladaFile(EnvironmentBasePtr penv, const string& filename,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
    return false;
}

inline bool RaveParseColladaFile(EnvironmentBasePtr penv, KinBodyPtr& pbody, const string& filename,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
    return false;
}

inline bool RaveParseColladaFile(EnvironmentBasePtr penv, RobotBasePtr& probot, const string& filename,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
    return false;
}

inline bool RaveParseColladaData(EnvironmentBasePtr penv, const string& pdata,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
    return false;
}

inline bool RaveParseColladaData(EnvironmentBasePtr penv, KinBodyPtr& pbody, const string& pdata,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
    return false;
}

inline bool RaveParseColladaData(EnvironmentBasePtr penv, RobotBasePtr& probot, const string& pdata,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
    return false;
}


inline void RaveWriteColladaFile(EnvironmentBasePtr penv, const std::string& filename,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
}

inline void RaveWriteColladaFile(KinBodyPtr pbody, const std::string& filename,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
}

inline void RaveWriteColladaFile(const std::list<KinBodyPtr>& listbodies, const std::string& filename,const AttributesList& atts)
{
    RAVELOG_ERROR("collada files not supported\n");
}

#endif

#endif
