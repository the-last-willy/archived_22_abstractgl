// #pragma once

// #include "mesh_instance.hpp"
// #include "mesh.hpp"
// #include "program.hpp"
// #include "uniform.hpp"

// #include <agl/all.hpp>

// #include <memory>
// #include <vector>

// namespace eng {

// struct RenderPass {
//     std::shared_ptr<Program> program = {};

//     std::vector<std::shared_ptr<MeshInstance>> mesh_instances;

//     std::vector<std::shared_ptr<Primitive>> primitives = {};
//     std::vector<agl::VertexArray> vertex_arrays = {};

//     std::map<std::string, std::shared_ptr<AnyUniform>> uniforms;
// };

// inline
// void configure(agl::VertexArray va, const Primitive& pi, const Program& po) {
//     if(pi.indices.buffer) {
//         element_buffer(va, pi.indices.buffer->opengl);
//     }
//     for(int i = 0; i < agl::active_attributes(po.program); ++i) {
//         auto aa = agl::active_attrib(po.program, agl::AttributeIndex(i));
//         auto ai = attribute_location(po.program, aa.name.c_str());
//         auto bi = agl::BindingIndex<GLuint>(i);
//         attribute_binding(va, ai, bi);
//         auto it = pi.attributes.find(aa.name);
//         if(it != end(pi.attributes)) {
//             auto& accessor = it->second;
//             attribute_format(
//                 va, ai,
//                 accessor.component_count,
//                 accessor.component_type,
//                 accessor.normalized,
//                 agl::Offset<GLuint>(0));
//             vertex_buffer(
//                 va, bi,
//                 accessor.buffer->opengl,
//                 agl::Offset<GLintptr>(
//                     accessor.buffer_view_byte_offset.value
//                     + accessor.byte_offset.value),
//                 accessor.buffer_view_byte_stride);
//             enable(va, ai);
//         } else {
//             // ?
//         }
//     }
// }

// inline
// void add(RenderPass& rp, const Mesh& m) {
//     for(auto& p : m.primitives) {
//         auto va = agl::vertex_array();
//         configure(va, *p, *rp.program);
//         rp.primitives.push_back(p);
//         rp.vertex_arrays.push_back(std::move(va));
//     }
// }

// inline
// void bind(const RenderPass&) {
//     // bind(rp.program);
// }

// inline
// void unbind(const RenderPass&) {
//     // unbind(rp.program);
// }

// // struct RenderPassBinding {
// //     const RenderPass& render_pass;

// //     RenderPassBinding(const RenderPass& rp)
// //         : render_pass(rp)
// //     {
// //         bind(rp.program);
// //     }
// // };

// inline
// void bind_uniforms(const RenderPass& rp) {
//     for(auto& [name, value] : rp.uniforms) {
//         auto ul = uniform_location(rp.program->program, name.c_str());
//         if(ul) {
//             value->set(rp.program->program, *ul);
//         }
//     }
// }

// inline
// void render(const RenderPass& rp) {
//     bind(*rp.program);
//     bind_uniforms(rp);
//     for(std::size_t i = 0; i < size(rp.vertex_arrays); ++i) {
//         auto& p = *rp.primitives[i];
//         bind(rp.vertex_arrays[i]);
//         bind(p);
//         eng::render(p);
//         unbind(p);
//     }
//     unbind(*rp.program);
// }

// }
