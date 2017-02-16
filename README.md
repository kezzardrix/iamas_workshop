# iamas_workshop
examples for workshop at iamas

some projects are depends on https://github.com/kezzardrix/ofxBlur

PointSpriteShading_normalAttribとなっているやつは、
gl_VertexIDの代わりにgl_Normalを使ってランダム関数を作るバージョン

グラボによって#extension GL_EXT_gpu_shader4 : enableが通らないため、gl_VertexIDが使えない

各プロジェクトのcommonフォルダのabs.glslinc.fragにグラボによって通らないバグがあるため、
トップにあるcommonフォルダと入れ替えて欲しい
